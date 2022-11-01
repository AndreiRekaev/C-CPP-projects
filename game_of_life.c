#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define X 80
#define Y 25


# MY GAME OF LIFE PROJECT

int **matrix_malloc();
void game_start(int **a, int **b);
void input(int **array);
void life_cycle(int **a, int **b);
int neighbours_check(int **a, int x, int y);
void draw(int **a);

int main() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, 1);
    keypad(stdscr, 1);

    int **a = matrix_malloc();
    int **b = matrix_malloc();
    input(a);
    draw(a);
    game_start(a, b);
    free(a);
    free(b);
    return 0;
}

void game_start(int **a, int **b) {
    int ticks = 0;
    int speed = 1;
    char key;
    while (1) {
        key = getch();
            if (key == 'q' || key == 'Q') {
                system("clear");
                break;
            }
            if (key == '1')
                speed = 1;
            if (key == '2')
                speed = 3;
            if (key == '3')
                speed = 5;
            if (key == '4')
                speed = 7;
            if (key == '5')
                speed = 10;
            if (key == 'p' || key == 'P') {
                char pause;
                pause = getch();
                while (1) {
                    draw(a);
                    pause = getch();
                    if (pause == 'p' || pause == 'P') {
                        break;
                    }
                }
            }
        if (ticks % 2 == 0) {
            life_cycle(a, b);
            draw(b);
        } else {
            life_cycle(b, a);
            draw(a);
        }
        ticks++;
        usleep(500000 / speed);
    }
}

void draw(int **a) {
    move(0, 0);
    printw("\t\t\t\t    GAME OF LIFE\n");
    printw("----------------------------------------");
    printw("----------------------------------------\n");
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (a[i][j] == 1) {
                printw("#");
            } else if (a[i][j] == 0) {
                printw(" ");
            }
        }
        printw("\n");
    }
    printw("----------------------------------------");
    printw("----------------------------------------\n");
    printw("\t    PRESS 1 - 5 TO SWITCH SPEED // P to pause // Q to exit");
    refresh();
}

void life_cycle(int **a, int **b) {
    int n;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            n = neighbours_check(a, j, i);
            if (a[i][j] == 0) {
                if (n == 3) {
                    b[i][j] = 1;
                } else {
                   b[i][j] = 0;
                }
            } else {
                if (n < 2 || n > 3)
                    b[i][j] = 0;
                else
                    b[i][j] = 1;
            }
        }
    }
}

int neighbours_check(int **a, int x, int y) {
    int neighbours = 0;
    int m, n;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            m = y + i;
            n = x + j;
            if (m < 0) {
                m = Y + m;
            } else if (m > Y - 1) {
                m = m - Y;
            }

            if (n < 0) {
                n = X + n;
            } else if (n > X - 1) {
                n = n - X;
            }
            if (a[m][n] == 1)
               neighbours++;
        }
    }
    return neighbours;
}

void input(int **array) {
        for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            scanf("%d", &array[i][j]);
        }
    }
    freopen("/dev/tty", "r", stdin);
}

int **matrix_malloc() {
    int **array = malloc(Y * X * sizeof(int) + Y * sizeof(int*));
    int *ptr = (int*)(array + Y);
    for (int i = 0; i < Y; i++)
        array[i] = ptr + X * i;
    return array;
}
