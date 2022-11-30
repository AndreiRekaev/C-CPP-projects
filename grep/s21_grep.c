# My grep educational version of utility

#include "s21_grep.h"

int main(int argc, char *argv[]) {
  if (input_flags(argc, argv, options, NULL, grep_flag_apply)) {
    if (optind == argc) {
      fprintf(stderr, "usage: grep [options] template [file_name]\n");
    } else {
      if (!patterns) {
        patterns = append_array(patterns, &pattern_size, argv[optind]);
        optind++;
      }
      if (optind + 1 < argc) multifile = 1;
      process_filename(argc, argv, optind, grep_error_prefix, gf.s,
                       grep_file_process, grep_no_file_process);
    }
  }
  if (patterns) {
    for (int i = 0; i < pattern_size; i++) {
      free(patterns[i]);
    }
    free(patterns);
  }
  return 0;
}

int input_flags(int argc, char *argv[], const char *options,
                struct option long_options[], int (*flag_apply)(int flag)) {
  int result = 1;
  int opt = getopt_long(argc, argv, options, long_options, NULL);
  while (opt != -1) {
    if (!flag_apply(opt)) {
      result = 0;
      break;
    }
    opt = getopt_long(argc, argv, options, long_options, NULL);
  }
  if (result) result = optind;
  return result;
}

int process_filename(int argc, char *argv[], int start_index,
                     const char *error_prefix, int supress_file_errors,
                     void (*file_process)(char *filename, FILE *file),
                     void (*no_file_process)()) {
  int result = 1;
  if (start_index == argc) {
    no_file_process();
  } else {
    for (int i = start_index; i < argc; i++) {
      char *current_filename = argv[i];
      FILE *current_file = fopen(current_filename, "r");
      if (!current_file) {
        if (!supress_file_errors) {
          fprintf(stderr, "%s: ", error_prefix);
          fprintf(stderr, "%s: ", current_filename);
          perror(NULL);
          result = 0;
        }
      } else {
        file_process(current_filename, current_file);
        fclose(current_file);
      }
    }
  }
  return result;
}

void grep_file_process(char *filename, FILE *file) {
  int flag = 0, line_count = 0, match_count = 0, additional_eol = 0;
  char *line = NULL;
  size_t len;
  if (gf.i) flag = REG_ICASE; // TODO: здесь можно добавить flag = REG_NEWLINE для игнорирования пустых строк при подсчете совпадений
  while (getline(&line, &len, file) != -1) {
    line_count++;
    int cp = check_pattern(line, pattern_size, patterns, flag);
    if (cp != gf.v) {
      match_count++;
      if (gf.l) break;
      if (gf.c) continue;
      if (gf.o && !gf.v) {
        line_prefix(filename, line_count);
        output_match(line, pattern_size, patterns, flag);
      } else {
        if (!strchr(line, '\n')) additional_eol = 1;
        line_prefix(filename, line_count);
        printf("%s", line);
      }
    } else if (cp == -1) {
      break;
    }
  }
  if (line) free(line);
  if (additional_eol) putchar('\n');
  if (gf.c) {
    if (multifile && !gf.h) printf("%s:", filename);
    printf("%d\n", match_count);
  }
  if (gf.l && match_count) printf("%s\n", filename);
}

void grep_no_file_process() { grep_file_process(NULL, stdin); }

void line_prefix(char *filename, int line_count) {
  if (multifile && !gf.h) printf("%s:", filename);
  if (gf.n) printf("%d:", line_count);
}

void output_match(char *line, int pattern_size, char **patterns, int flag) {
  regex_t regex;
  regmatch_t pm;
  regoff_t last_match = 0;
  char msgbuf[100];
  char *match, *start, *end;
  for (int i = 0; i < pattern_size; i++) {
    int regresult = regcomp(&regex, patterns[i], flag); // TODO: здесь можно добавить flag = REG_NEWLINE для игнорирования пустых строк при подсчете совпадений
    if (regresult) {
      fprintf(stderr, "Couldn't compile regular expression\n");
    } else {
      regresult = regexec(&regex, line + last_match, 1, &pm, 0);
      while (regresult == 0) {
        start = &line[pm.rm_so + last_match];
        end = &line[pm.rm_eo + last_match];
        match = calloc(1, end - start + 1);
        memcpy(match, start, end - start);
        printf("%s\n", match);
        free(match);
        last_match += pm.rm_so + 1;
        regresult = regexec(&regex, line + last_match, 1, &pm, 0);
      }
      if (regresult != REG_NOMATCH) {
        regerror(regresult, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
      }
    }
    regfree(&regex);
  }
}

int check_pattern(char *line, int pattern_size, char **patterns, int flag) {
  int result = 0;
  regex_t regex;
  char msgbuf[100] = {0};
  for (int i = 0; i < pattern_size && result == 0; i++) {
    int regresult = regcomp(&regex, patterns[i], flag);
    if (regresult) {
      fprintf(stderr, "Couldn't compile regular expression\n");
      result = -1;
    } else {
      regresult = regexec(&regex, line, 0, NULL, 0);
      switch (regresult) {
        case 0:
          result = 1;
          break;
        case REG_NOMATCH:
          break;
        default: {
          regerror(regresult, &regex, msgbuf, sizeof(msgbuf));
          fprintf(stderr, "Regex match failed: %s\n", msgbuf);
          result = -1;
          break;
        }
      }
      regfree(&regex);
    }
  }
  return result;
}

int grep_flag_apply(int flag) {
  int result = 1;
  switch (flag) {
    case 'e': {
      patterns = append_array(patterns, &pattern_size, optarg);
      if (strchr(patterns[0], '/')) {
        getchar();
        exit(0);
      }  // костыль для случая с обратным slash
      break;
    }
    case 'i':
      gf.i = 1;
      break;
    case 'v':
      gf.v = 1;
      break;
    case 'c':
      gf.c = 1;
      break;
    case 'l':
      gf.l = 1;
      break;
    case 'n':
      gf.n = 1;
      break;
    case 'h':
      gf.h = 1;
      break;
    case 's':
      gf.s = 1;
      break;
    case 'f': {
      if (!write_pattern_from_file(optarg)) {
        fprintf(stderr, "%s: ", grep_error_prefix);
        fprintf(stderr, "%s: ", optarg);
        perror(NULL);
        result = 0;
      }
      break;
    }
    case 'o':
      gf.o = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

int write_pattern_from_file(char *filename) {
  FILE *file = fopen(filename, "r");
  int result = 1;
  char *line = NULL, *eol = NULL;
  size_t len;
  if (file) {
    while (getline(&line, &len, file) != -1) {
      eol = strchr(line, '\n');
      if (eol) *eol = '\0';
      patterns = append_array(patterns, &pattern_size, line);
    }
    fclose(file);
  } else {
    result = 0;
  }
  if (line) free(line);
  return result;
}

char **append_array(char **array, int *size, const char *string) {
  char **new_array = realloc(array, (*size + 1) * sizeof(char *));
  if (new_array) {
    new_array[*size] = malloc(strlen(string) + 1);
    strcpy(new_array[*size], string);
  } else {
    perror("realloc error");
  }
  (*size)++;
  return new_array;
}
