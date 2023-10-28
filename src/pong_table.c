#include <stdio.h>

void main() {
    int ball_i = 13, ball_j = 20, left_rocket = 13, right_rocket = 13;

    for (int i=0; i<=25; i++) {
        for (int j=0; j<=80; j++) {
            if (i == 0 || i == 25 ) {
            printf("-");
            }
            else if (i == ball_i && j == ball_j){
                printf("*");
            }
            else if ((i == left_rocket || i == left_rocket + 1 || i == left_rocket + 2 || i == right_rocket || i == right_rocket + 1 || i == right_rocket + 2) && (j == 10 || j == 70)){
                printf("|");
            } 
            else if ( j == 40 ) {
                printf(":");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}