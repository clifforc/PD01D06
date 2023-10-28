#include <stdio.h>
#include <math.h>
/*Необходимые переменные 
1. Итые, житые координаты шарика ball_i, ball_j
2. Направление шарика по итым, житым координатам nap_ver, nap_gor
3. Итые координаты верхних частей ракеток left_rocket, right_rocket
4. Счёт игроков left_score, right_score
5. Кто начинает who
6. Управление left, right
* Размер поля Hight 
*/

int ball_i, ball_j, nap_ver, nap_gor, left_rocket, right_rocket, left_score, right_score;

int main(void){
    char who, left, right;
    int flag = 1, left_rocket = 12, right_rocket = 12, left_score = 0, right_score = 0, nap_ver, nap_gor, ball_i, ball_j;
    printf("Who starts?(l/r) ");
    who = getchar();
    while (left_score < 21 && right_score < 21){
        if (who == 'l'){
            ball_i = 13;
            ball_j = 11;
            nap_gor = 1;
        }else if (who == 'r')
        {
            ball_i = 13;
            ball_j = 69;
            nap_gor = -1;
        }
        
        while (flag == 1){
            print_field(ball_i, ball_j, right_rocket, left_rocket);
            if (who == 'l'){
                while (left != 'a' || left != 'z' || left != ' '){
                    left = getchar();
                }
                if (left == 'a'){
                    nap_ver = -1;
                }else{
                    nap_ver = 1;
                }
                while (right != 'm' || right != 'k' || right != ' '){
                    right = getchar();
                }
                if (right == 'k'){
                    nap_ver = -1;
                }else{
                    nap_ver = 1;
                }
                nap_gor = 1;
            }
            if (who == 'r'){
                while (right != 'k' || right != 'm' || right != ' '){
                    right = getchar();
                }
                if (right == 'k'){
                    nap_ver = -1;
                }else{
                    nap_ver = 1;
                }
                while (left != 'a' || left != 'z' || left != ' '){
                    left = getchar();
                }
                if (left == 'a'){
                    nap_ver = -1;
                }else{
                    nap_ver = 1;
                }
                nap_gor = -1;                          
            }

            if (ball_i == 1 || ball_i == 25){
                nap_ver *= -1;
            }
            ball_i += nap_ver;
            if ((ball_j == 11) && (nap_gor == -1)){
                if (ball_i == left_rocket || ball_i == left_rocket +1 || ball_i == left_rocket + 2){
                    nap_gor *= -1;
                }
                else{
                    right_score += 1;
                    who = 'l';
                    flag = 0;
                }
            }
            if ((ball_j == 69) && (nap_gor == 1)){
                if (ball_i == right_rocket || ball_i == right_rocket + 1 || ball_i == right_rocket + 2){
                    nap_gor *= -1;
                }
                else{
                    left_score += 1;
                    who = 'r';
                    flag = 0;
                }
            }
            ball_j += nap_gor;
        }
    }
}