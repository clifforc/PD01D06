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
int left_insert(char left);
int right_insert(char right);
int move_rocket(int rocket, int move);
int ball_gor();

int main(){
    char who, left, right;
    int flag = 1, left_rocket = 12, right_rocket = 12, left_score = 0, right_score = 0, nap_ver, nap_gor, ball_i, ball_j;
    printf("Who starts?(l/r) ");
    while (who != 'l' && who != 'r'){
        who = getchar();
    }
    while (left_score < 21 || right_score < 21){
        if (who == 'l'){
            ball_i = 13;
            ball_j = 11;
            nap_gor = 1;
            nap_ver = -1;
        }else if (who == 'r')
        {
            ball_i = 13;
            ball_j = 69;
            nap_gor = -1;
            nap_ver = -1;
        }
        print_field(ball_i, ball_j, right_rocket, left_rocket);
        printf("%d : %d\n", left_score, right_score);
        while(ball_j != 10 && ball_j != 70){
            left_rocket = move_rocket(left_rocket, left_insert('*'));
            right_rocket = move_rocket(right_rocket, right_insert('*'));
            if (ball_i == 1 || ball_i ==25){
                nap_ver *= -1;
            } 
            ball_i += nap_ver;
            if ((ball_i == left_rocket || ball_i == left_rocket + 1 || ball_i == left_rocket + 2) && ball_j == 11){
                nap_gor  = 1;
            }
            else if ((ball_i == right_rocket || ball_i == right_rocket + 1 || ball_i == right_rocket + 2) && ball_j == 69)
            {
                nap_gor  = -1;
            }
            else if ((ball_i != left_rocket && ball_i != left_rocket + 1 && ball_i != left_rocket + 2) && ball_j == 11)
            {
                right_score += 1;
                flag = 0;
                who = 'l';
            }
            else if ((ball_i != right_rocket && ball_i != right_rocket + 1 && ball_i != right_rocket + 2) && ball_j == 69)
            {
                left_score += 1;
                flag = 0;
                who = 'r';
            }
            ball_j += nap_gor;
            print_field(ball_i, ball_j, right_rocket, left_rocket);
            printf("%d : %d\n", left_score, right_score);
        }
        flag = 1; 
    }
    if (right_score > left_score){
        printf("Congrats to right player!!!");
    }
    else if (right_score < left_score)
    {
        printf("Congrats to left player!!!");
    }
    
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
            else if ((((i == left_rocket || i == left_rocket + 1 || i == left_rocket + 2 ) && (j == 10)) || ((i == right_rocket || i == right_rocket + 1 || i == right_rocket + 2)) && (j == 70))){
                printf("|");
            } 
            else if (j == 39) {
                printf(":");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int left_insert(char left){
    while (left != 'a' && left != 'z' && left != ' '){
        left = getchar();
        if (left == 'a'){
            return -1;
        }
        else if (left == 'z'){
            return 1;
        }
        else if(left == ' '){
            return 0;
        }
    }
}

int right_insert(char right){
    while (right != 'k' && right != 'm' && right != ' '){
        right = getchar();
        if (right == 'k'){
            return -1;
        }
        else if (right == 'm'){
            return 1;
        }
        else if (right == ' ')
        {
            return 0;
        }
        
    }
}
int move_rocket(int rocket, int move){
    rocket += move;
    if (rocket == 0 || rocket == 24){
        rocket -= move;
        return rocket;
    }
    else{
        return rocket;
    }
}
int ball_ver(int ball_i, int nap_ver){
    ball_i += nap_ver;
    if (ball_i == 0 || ball_i == 26){
        ball_i -= nap_ver;
        return ball_i;
    }
    else{
        return ball_i;
    }
}
int ball_gor(int ball_j, int nap_gor){
    ball_j += nap_gor;
    return ball_j;
}