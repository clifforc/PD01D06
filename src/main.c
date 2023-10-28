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


int print_field(int ball_i, int ball_j, int right_rocket, int left_rocket);


int main(){
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
            printf("%d : %d\n", left_score, right_score);
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
            if (who == 'l'){
                while (left != 'a' && left != 'z' && left != ' '){
                    scanf("%c", &left);
                
                    if (left == 'a'){
                        nap_ver = -1;
                        left_rocket --;
                    }else if (left == 'z')
                    {
                        nap_ver = 1;
                        left_rocket ++;
                    }
                }
                while (right != 'm' && right != 'k' && right != ' '){
                    scanf("%c", &right);
                    if (right == 'k'){
                        nap_ver = -1;
                        right_rocket--;
                    }else if (right == 'm')
                    {
                        nap_ver = 1;
                        right_rocket ++;
                    }
                }
                nap_gor = 1;
            }
            if (who == 'r'){
                while (right != 'k' && right != 'm' && right != ' '){
                    scanf("%c", &right);
                    if (right == 'k'){
                        nap_ver = -1;
                        right_rocket --;
                    }else if (right == 'm')
                    {
                        nap_ver = 1;
                        right_rocket --;
                    }
                }
                while (left != 'a' && left != 'z' && left != ' '){
                    scanf("%c", &left);
                    if (left == 'a'){
                        nap_ver = -1;
                        left_rocket --;
                    }else if (left == 'z')
                    {
                        nap_ver = 1;
                        left_rocket ++;
                    }
                }
                nap_gor = -1;                          
            }

            if (ball_i == 1 && nap_ver == -1){
                nap_ver *= -1;
            }
            else if (ball_i == 25 && nap_ver == 1)
            {
                nap_ver *= -1;
            }
            
            ball_i += nap_ver;
            ball_j += nap_gor;
            left = '1';
            right = '2';
        }
        flag = 1;
    }

    return 0;
}

int print_field(int ball_i, int ball_j, int right_rocket, int left_rocket){
    for (int i=0; i<=26; i++) {
        for (int j=0; j<=80; j++) {
            if (i == 0 || i == 26 ) {
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
    return 0;
}