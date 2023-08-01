#ifndef SRC_3DVIEWER_H_
#define SRC_3DVIEWER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUMNS 3
#define EPS 1e-7
#define M_RAD 0.017453292519943295474

/**
 * \brief структура для хранения данных объекта
 * \param **matrix указатель для хранения вершин объекта
 * \param rows количество строк
 * \param columns количество столбцов
 * \param avip общее количесвто точек для отрисовки ребер
 * \param count количество полигонов
 * \param *element_array указатель на массив индексов, если файл содержит
 * полигоны \param minmax[6] массив с мин-макс значениями для задания поля
 * отрисовки
 */

typedef struct {
  double **matrix;
  int rows;
  int columns;
  int avip;
  int count;
  int *element_array;
  double minmax[6];
} matrix_t;
/** \defgroup parse 3DViewer
    @{
*/
/**
 * \brief производит операцию с файлом.
 * \param *file_name путь до файла.
 * \param *vertexes структура matrix_t для данных.
 * \return 0-успех, 1-ошибка.
 */
int parse(const char *file_name, matrix_t *vertexes);

/**
 * \brief проверяет какие данные содержит строка.
 * \param[in] *str строка из файла.
 * \return 1 - вершины, 2 - полигон, 0 - другое.
 */
int check(char *str);

/**
 * @brief заполнение минмаксного массива данными
 * @param *V указатель на структуру данных matrix_t
 * @param x по оси x
 * @param y по оси y
 * @param z по оси z
 */
void fill_minmax(matrix_t *V, double x, double y, double z);

/**
 * @brief initial_minmax установка минмакса от координат первой точки
 * @param x значение по оси x
 * @param y значение по оси y
 * @param z значение по оси z
 */
void initial_minmax(double *, double x, double y, double z);

/**
 * @brief counting подсчет количества вершин, полигонов и всех точек в полигонах
 * @param fptr Указатель на FILE
 * @param ver хранение количества вершин
 * @param pol хранение количества полигонов
 * @param all хранение количества всех точек в полигонах
 * @return 0-успех, 1-ошибка
 */
int counting(FILE *fptr, int *ver, int *pol, int *all);

/**
 * @brief create_matrix выделение памяти для хранения вершин и индексов
 * @param rows количество рядов
 * @param polygon количество полигонов
 * @param avip количество всех точек в полигонах
 * @param v указатель на структуру matrix_t
 * @return 0-успех, 1-ошибка
 */
int create_matrix(int rows, int polygon, int avip, matrix_t *v);

/**
 * @brief fill_matrix_t заполнение структуры matrix_t данными из файла
 * @param fptr указатель на FILE
 * @param v указатель на структуру matrix_t
 * @return 0-успех, 1-ошибка
 */
int fill_matrix_t(FILE *fptr, matrix_t *v);

/**
 * @brief remove_matrix очистка структуры matrix_t
 * @param v указатель на структуру
 */
void remove_matrix(matrix_t *v);

// void print(matrix_t *V);

// affine transformations
/**
 * @brief zoom увеличение/уменьшение объекта
 * @param V указатель на структуру данных
 * @param value значение во сколько раз изменить размер
 * @return 0-успех, 1-ошибка
 */
int zoom(matrix_t *V, double value);

/**
 * @brief around_x вращение вокруг оси x
 * @param V  указатель на структуру
 * @param angle угол вращения в радианах
 * @return 0-успех, 1-ошибка
 */
int around_x(matrix_t *V, double angle);

/**
 * @brief around_y вращение вокруг оси y
 * @param V указатель на структуру
 * @param angle угол вращения в радианах
 * @return 0-успех, 1-ошибка
 */
int around_y(matrix_t *V, double angle);

/**
 * @brief around_z вращение вокруг оси z
 * @param V указатель на структуру
 * @param angle угол вращения в радианах
 * @return 0-успех, 1-ошибка
 */
int around_z(matrix_t *V, double angle);

/**
 * @brief translation_x перемещение объекта по оси x
 * @param V указатель на структуру
 * @param val значение на которое сместить по оси x
 * @return 0-успех, 1-ошибка
 */
int translation_x(matrix_t *V, double val);

/**
 * @brief translation_y перемещение объекта по оси y
 * @param V указатель на структуру
 * @param val значение на которое сместить по оси y
 * @return 0-успех, 1-ошибка
 */
int translation_y(matrix_t *V, double val);

/**
 * @brief translation_z перемещение объекта по оси z
 * @param V указатель на структуру
 * @param val значение на которое сместить по оси z
 * @return 0-успех, 1-ошибка
 */
int translation_z(matrix_t *V, double val);
/** @}*/
#ifdef __cplusplus
}
#endif

#endif  // SRC_3DVIEWER_H_
