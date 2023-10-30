#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
/*Необходимые переменные
1. Итые, житые координаты шарика ball_i, ball_j
2. Направление шарика по итым, житым координатам nap_ver, nap_gor
3. Итые координаты верхних частей ракеток left_rocket, right_rocket
4. Счёт игроков left_score, right_score
5. Кто начинает who
6. Управление left, right
* Размер поля Hight
*/
int print_field(int ball_i, int ball_j, int right_rocket, int left_rocket);

int main() {
  char who = '*';
  int left_score = 0, right_score = 0, nap_ver, nap_gor, ball_i, ball_j;

  struct termios origTerm, newTerm;
  tcgetattr(STDIN_FILENO, &origTerm);
  newTerm = origTerm;
  newTerm.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newTerm);
  printf("Who starts?(l/r) ");
  while (who != 'l' && who != 'r') {
    who = getchar();
  }
  while (left_score < 21 && right_score < 21) {
    if (who == 'l') {
      ball_i = 13, ball_j = 11, nap_gor = 1, nap_ver = -1;
    } else if (who == 'r') {
      ball_i = 13, ball_j = 69, nap_gor = -1, nap_ver = -1;
    }
    int flag = 1, left_rocket = 12, right_rocket = 12;
    print_field(ball_i, ball_j, right_rocket, left_rocket);
    printf("                                     %d : %d\n", left_score, right_score);
    while (flag == 1) {
      struct timeval timeout;
      fd_set readfds;
      FD_ZERO(&readfds);
      FD_SET(STDIN_FILENO, &readfds);
      timeout.tv_sec = 0;
      timeout.tv_usec = 80000;

      int key_is_pressed =
          select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);
      if (key_is_pressed != 0) {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
          char input;
          read(STDIN_FILENO, &input, 1);
          if (input == 'a' && left_rocket > 1) {
            left_rocket--;
          } else if (input == 'z' && left_rocket < 23) {
            left_rocket++;
          } else if (input == 'k' && right_rocket > 1) {
            right_rocket--;
          } else if (input == 'm' && right_rocket < 23) {
            right_rocket++;
          }
        }
      }
      if (ball_i == 1 || ball_i == 25) {
        nap_ver *= -1;
      }
      ball_i += nap_ver;
      if ((ball_i == left_rocket || ball_i == left_rocket + 1 ||
           ball_i == left_rocket + 2) &&
          ball_j == 11) {
        nap_gor = 1;
      } else if ((ball_i == right_rocket || ball_i == right_rocket + 1 ||
                  ball_i == right_rocket + 2) &&
                 ball_j == 69) {
        nap_gor = -1;
      } else if ((ball_i != left_rocket && ball_i != left_rocket + 1 &&
                  ball_i != left_rocket + 2) &&
                 ball_j == 11) {
        right_score += 1, flag = 0, who = 'l';
      } else if ((ball_i != right_rocket && ball_i != right_rocket + 1 &&
                  ball_i != right_rocket + 2) &&
                 ball_j == 69) {
        left_score += 1, flag = 0, who = 'r';
      }
      ball_j += nap_gor;
      print_field(ball_i, ball_j, right_rocket, left_rocket);
      printf("                                     %d : %d\n", left_score, right_score);
    }
  }
  if (right_score > left_score) {
    printf("                    Congrats to right player!!!");
  } else if (right_score < left_score) {
    printf("                    Congrats to left player!!!");
  }
}

int print_field(int ball_i, int ball_j, int right_rocket, int left_rocket) {
  for (int i = 0; i <= 26; i++) {
    for (int j = 0; j <= 80; j++) {
      if (i == 0 || i == 26) {
        printf("-");
      } else if (i == ball_i && j == ball_j) {
        printf("*");
      } else if ((((i == left_rocket || i == left_rocket + 1 ||
                    i == left_rocket + 2) &&
                   (j == 10))) ||
                 (((i == right_rocket || i == right_rocket + 1 ||
                    i == right_rocket + 2)) &&
                  (j == 70))) {
        printf("|");
      } else if (j == 39) {
        printf(":");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}