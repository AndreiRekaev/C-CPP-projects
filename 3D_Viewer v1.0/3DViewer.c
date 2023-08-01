#include "3DViewer.h"

int parse(const char *file_name, matrix_t *vertexes) {
  int res = 0;
  FILE *fptr = NULL;

  if (!file_name || !vertexes) res = 1;
  if (!res) (fptr = fopen(file_name, "r")) ? (res = 0) : (res = 1);
  if (!res) {
    int vertex = 0, face = 0, avip = 0;  // avip - all indexes in poligones x 2
    res = counting(fptr, &vertex, &face, &avip);
    avip *= 2;
    rewind(fptr);

    if (!res) res = create_matrix(vertex, face, avip, vertexes);
    if (!res) res = fill_matrix_t(fptr, vertexes);
    if (res) remove_matrix(vertexes);
    fclose(fptr);
  }
  return res;
}

int counting(FILE *fptr, int *vertex, int *face, int *all) {
  int res = 0;
  char temp[256] = {0};
  while (!feof(fptr) && !res) {
    if (fgets(temp, 255, fptr)) {
      int type = check(temp);
      if (type == 1) ++(*vertex);
      if (type == 2) {
        char *ptr = temp;
        ptr += (int)strspn(ptr, "f \t\n");
        // if (*ptr) ++(*face);
        int size = 0;
        for (; *ptr && !res;) {
          int value = strtol(ptr, &ptr, 10);
          if (value != 0) {
            ++(*all);
            ++size;
            ptr += (int)strcspn(ptr, " ");
          } else {
            res = 1;
          }
          ptr += (int)strspn(ptr, " \f\n\r\t\v");
        }
        if (size > 2) ++(*face);
      }
    }
  }
  if (*vertex < 1) res = 1;  //полигонов может не быть а 1 точка должна быть

  return res;
}

int check(char *str) {
  int result = 0;
  char space[3] = " \t";
  str += (int)strspn(str, space);
  if (*str == 'v' && *(str + 1) == ' ') {
    result = 1;
  } else if (*str == 'f' && *(str + 1) == ' ') {
    result = 2;
  }
  return result;
}

int create_matrix(int rows, int polygon, int avip, matrix_t *v) {
  int res = 0;
  if (!v || rows < 1 || COLUMNS < 1) res = 1;
  if (!res) {
    v->matrix = (double **)malloc(rows * sizeof(double *));
    if (!v->matrix) res = 1;
    if (!res) {
      *(v->matrix) = (double *)calloc(rows * COLUMNS, sizeof(double));
      *(v->matrix) ? (res = 0) : (res = 1);
      if (!res && avip > 0) {
        v->element_array = (int *)calloc(avip, sizeof(int));
        (v->element_array) ? (res = 0) : (res = 1);
      }
      if (res) remove_matrix(v);
      if (!res) {
        for (int i = 0; i < rows; i++) {
          v->matrix[i] = *v->matrix + (i * COLUMNS);
        }
        v->rows = rows;
        v->avip = avip;
        v->count = polygon;
        v->columns = COLUMNS;
      }
    }
  }
  return res;
}
int fill_matrix_t(FILE *fptr, matrix_t *v) {
  int res = 0, *iptr = NULL;
  char temp[256] = {0};
  if (!v || !v->matrix) res = 1;
  if (!res) iptr = v->element_array;
  for (int row = 0; !feof(fptr) && !res;) {
    if (fgets(temp, 255, fptr)) {
      int type = check(temp);
      if (type == 1) {
        double x = 0, y = 0, z = 0;
        int correct = sscanf(temp, " v %lf%lf%lf", &x, &y, &z);
        v->matrix[row][0] = x;
        v->matrix[row][1] = y;
        correct == 3 ? (v->matrix[row][2] = z) : (v->matrix[row][2] = 0);
        if (correct < 1) res = 1;
        if (!row) initial_minmax(v->minmax, x, y, z);
        if (row) fill_minmax(v, x, y, z);
        ++row;
      }
      if (type == 2) {
        int size = 0, first = 0;
        char *ptr = temp;
        ptr += (int)strspn(ptr, "f \t\n");
        for (; *ptr && !res;) {
          int value = strtol(ptr, &ptr, 10);
          if (value != 0 && abs(value) <= v->rows) {
            ++size;
            *iptr = (value > 0) ? (value - 1) : (v->rows + value);
            if (first) {
              ++iptr;
            } else {
              first = (value > 0) ? (value) : (v->rows + value + 1);
            }
            *iptr = (value > 0) ? (value - 1) : (v->rows + value);
            ++iptr;
            ptr += (int)strcspn(ptr, " ");
          } else {
            res = 1;
          }
          ptr += (int)strspn(ptr, " \f\n\r\t\v");
        }
        if (first) *iptr = first - 1;
        if (iptr - v->element_array < v->avip - 1) ++iptr;
      }
    }
  }
  return res;
}
void initial_minmax(double *arr, double x, double y, double z) {
  arr[0] = x;
  arr[1] = x;
  arr[2] = y;
  arr[3] = y;
  arr[4] = z;
  arr[5] = z;
}
void fill_minmax(matrix_t *V, double x, double y, double z) {
  if (V->minmax[0] > x) V->minmax[0] = x;
  if (V->minmax[1] < x) V->minmax[1] = x;
  if (V->minmax[2] > y) V->minmax[2] = y;
  if (V->minmax[3] < y) V->minmax[3] = y;
  if (V->minmax[4] > z) V->minmax[4] = z;
  if (V->minmax[5] < x) V->minmax[5] = z;
}
void remove_matrix(matrix_t *v) {
  if (v) {
    if (v->matrix) {
      if (*v->matrix) free(*v->matrix);
      free(v->matrix);
    }
    if (v->element_array) free(v->element_array);
    v->rows = 0;
    v->avip = 0;
    v->count = 0;
    v->columns = 0;
    v->matrix = NULL;
    v->element_array = NULL;
  }
}
/*
void print(matrix_t *V) {
  if (V && V->matrix) {
    for (int i = 0; i < V->rows; i++) {
      for (int k = 0; k < COLUMNS; k++) {
        fprintf(stderr, "%lf ", V->matrix[i][k]);
      }
      fprintf(stderr, "\n");
    }
    fprintf(stderr, "#vertexes - %d\n", V->rows);
  }
  if (V && V->element_array) {
    for (int i = 0; i < V->avip; i++) {
      fprintf(stderr, "#vertexes - %d ", V->rows);
      if (i % V->avip / V->count == 0 || i != 0) fprintf(stderr, "\n");
    }
    fprintf(stderr, "#polygon - %d\n", V->rows);
  }
}
*/
int zoom(matrix_t *V, double value) {
  int res = 0;
  if (!V || !V->matrix || value == 0) res = 1;
  if (!res) {
    for (int i = 0; i < V->rows * V->columns; i++) {
      *(*V->matrix + i) = *(*V->matrix + i) * value;
    }
  }
  return res;
}

// rotation
// around x
int around_x(matrix_t *V, double angle) {
  int res = 0;
  if (!V || !V->matrix) res = 1;
  if (!res && angle != 0) {
    double s = sin(angle);
    double c = cos(angle);
    double ms = -s;
    for (int i = 0; i < V->rows * V->columns; i += 3) {
      // double x = *(V->matrix[0] + i);
      double y = *(V->matrix[0] + i + 1);
      double z = *(V->matrix[0] + i + 2);
      *(V->matrix[0] + i + 1) = y * c + z * ms;
      *(V->matrix[0] + i + 2) = y * s + z * c;
    }
  }
  return res;
}
// around y
int around_y(matrix_t *V, double angle) {
  int res = 0;
  if (!V || !V->matrix) res = 1;
  if (!res && angle != 0) {
    double s = sin(angle);
    double c = cos(angle);
    double ms = -s;
    for (int i = 0; i < V->rows * V->columns; i += 3) {
      double x = *(V->matrix[0] + i);
      // double y = *(V->matrix[0] + i + 1);
      double z = *(V->matrix[0] + i + 2);
      *(V->matrix[0] + i) = x * c + z * s;
      *(V->matrix[0] + i + 2) = x * ms + z * c;
    }
  }
  return res;
}

// ariund z
int around_z(matrix_t *V, double angle) {
  int res = 0;
  if (!V || !V->matrix) res = 1;
  if (!res && angle != 0) {
    double s = sin(angle);
    double c = cos(angle);
    double ms = -s;
    for (int i = 0; i < V->rows * V->columns; i += 3) {
      double x = *(V->matrix[0] + i);
      double y = *(V->matrix[0] + i + 1);
      // double z = *(V->matrix[0] + i + 2);
      *(V->matrix[0] + i) = x * c + y * ms;
      *(V->matrix[0] + i + 1) = x * s + y * c;
    }
  }
  return res;
}

// translations

int translation_x(matrix_t *V, double val) {
  int res = 0;
  if (!V || !V->matrix) res = 1;
  if (!res) {
    for (int i = 0; i < V->rows * V->columns; i += 3) {
      *(*V->matrix + i) += val;
    }
  }
  return res;
}

int translation_y(matrix_t *V, double val) {
  int res = 0;
  if (!V || !V->matrix) res = 1;
  if (!res) {
    for (int i = 1; i < V->rows * V->columns; i += 3) {
      *(*V->matrix + i) += val;
    }
  }
  return res;
}

int translation_z(matrix_t *V, double val) {
  int res = 0;
  if (!V || !V->matrix) res = 1;
  if (!res) {
    for (int i = 2; i < V->rows * V->columns; i += 3) {
      *(*V->matrix + i) += val;
    }
  }
  return res;
}
