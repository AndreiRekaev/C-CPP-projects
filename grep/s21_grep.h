#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#define _POSIX_C_SOURCE 200809L
#include <ctype.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int o;
} grep_flags;

grep_flags gf = {0};

char** patterns = NULL;
int pattern_size = 0;
const char* grep_error_prefix = "s21_grep";
int multifile = 0;

// Функции для парсинга флагов и файлов
int input_flags(int argc, char* argv[], const char* options,
                struct option long_options[], int (*flag_apply)(int flag));
int process_filename(int argc, char* argv[], int start_index,
                     const char* error_prefix, int supress_file_errors,
                     void (*file_process)(char* filename, FILE* file),
                     void (*no_file_process)());

int grep_flag_apply(int flag);  // включаем флаги
char** append_array(
    char** array, int* size,
    const char* string);  // выделяем память для заполнения массива
int check_pattern(char* line, int pattern_size, char** patterns,
                  int flag);  // проверяем совпадения
void output_match(char* line, int pattern_size, char** patterns,
                  int flag);  // выводим совпадения на экран для флага -о
int write_pattern_from_file(char* filename);  // берем шаблоны из файла
void grep_file_process(char* filename,
                       FILE* file);  // функция логики работы флагов
void grep_no_file_process();
void line_prefix(char* filename,
                 int line_count);  // печатаем имена файлов и номера строк

const char* options = "e:ivclnhsf:o";

#endif  // SRC_GREP_S21_GREP_H_
