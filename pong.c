#include <stdio.h>

#define X 80
#define Y 25

void field(int posx, int posy, int ry, int ly);
void score(int s1, int s2);
void clearScreen(void);

int main() {
    int posx = X / 2;
    int posy = Y / 2;
    int ly = 11;
    int ry = 15;
    int s1 = 0;
    int s2 = 0;
    int xd = 1;
    int yd = -1;
    char key;
    while (key != 'q') {
        score(s1, s2);
        field(posx, posy, ry, ly, xd, yd, s1, s2);
        key = getchar();
        if (key == 'a' && (ly - 2) != 0) {
            ly--;
        }
        if (key == 'z' && (ly + 2) != Y - 1) {
            ly++;
        }
        if (key == 'k' && (ry - 2) != 0) {
            ry--;
        }
        if (key == 'm' && (ry + 2) != Y - 1) {
            ry++;
        }
        if (posy == 1 || posy == Y - 2) {
        yd = -yd;
        }
        if (posx == 3 &&
            (posx == ly - 1 || posy == ly  || posy == ly + 1)) {
            xd = -xd;
        }
        if (posx == 77 &&
            (posy == ry - 1 || posy == ry  || posy == ry + 1)) {
            xd = -xd;
        }
        if (posx < 2) {
            s2++;
            posx = 50;
            posy = Y/2;
        }
        if (posx > X - 3) {
            s1++;
            posx = 30;
            posy = Y / 2;
        }
        if (s1 == 21) {
            printf("\n\t CONGRATULATION!!! PLAYER 1 IS WON BY %d TO %d.", s1, s2);
            return 0;
        } else if (s2 == 21) {
            printf("\n\t CONGRATULATION!!! PLAYER 2 IS WON BY %d TO %d.", s1, s2);
            return 0;
        }
        posy += yd;
        posx += xd;
        clearScreen();
    }
    return 0;
}

void field(int posx, int posy, int ry, int ly) {
    for (int i = 0; i <= Y; i++) {
        for (int j = 0; j <= X; j++) {
            if (posx == j && posy == i) {
                printf("@");
            } else {
                if ((j == 0 && i != 0 && i != Y) ||
                        (j == X && i != 0 && i != Y) ||
                        (j == X / 2)) {
                    printf("|");
                } else if (j == 3 && ((i == ly - 1) || i == ly || (i == ly + 1))) {
                    printf("]");
                } else if (j == X - 3 && ((i == ry - 1) || i == ry || (i == ry + 1))) {
                    printf("[");
                } else if ((i == 0 || i == Y) && (j > 0 && j < X)) {
                    printf("-");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void score(int s1, int s2) {
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x <= X; ++x) {
            if ((y == 0 || y == 2) && (x != 0 && x != X )) {
                printf("-");
            } else if (y == 1 && (x == 0 || x == 80)) {
                printf("|");
            } else if (x == 4) {
                printf("Press q to exit");
            } else if (x == 14) {
                printf("Player 1  %d | %d  Player 2       ", s1, s2);
            }  else if (y == 1 && x < X - 45) {
                printf(" ");
            } else if (y != 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void clearScreen(void) {
    printf("\33[0d\33[2J");
}
