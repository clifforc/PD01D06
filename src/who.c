if (who == 'l'){
                while (left != 'a' && left != 'z' && left != ' '){
                    left = getchar();                
                    if (left == 'a'){
                        left_rocket --;
                        nap_ver = -1;
                    }else if (left == 'z')
                    {
                        left_rocket ++;
                        nap_ver = 1;
                    }
                }
                while (right != 'm' && right != 'k' && right != ' '){
                    right = getchar();
                    if (right == 'k'){
                        right_rocket--;
                        nap_ver = -1;
                    }else if (right == 'm')
                    {
                        right_rocket ++;
                        nap_ver = 1;
                    }
                }
                nap_gor = 1;
        }
        if (who == 'r'){
            while (right != 'k' && right != 'm' && right != ' '){
                right = getchar();
                if (right == 'k'){
                    right_rocket --;
                    nap_ver = -1;
                }else if (right == 'm')
                {
                    right_rocket ++;
                }
            }
            while (left != 'a' && left != 'z' && left != ' '){
                left = getchar();
                if (left == 'a'){
                    left_rocket --;
                    nap_ver = -1;
                }else if (left == 'z')
                {
                    left_rocket ++;
                    nap_ver = 1;
                }
            }
            nap_gor = -1;                          
        }
        
        while (flag == 1){
            
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
                while (left != 'a' && left != 'z' && left != ' ' && left != '\n'){
                    left = getchar();                
                    if (left == 'a' && left_rocket != 1){
                        left_rocket --;
                    }else if (left == 'z' && left_rocket != 23)
                    {
                        left_rocket ++;
                    }
                }
                while (right != 'm' && right != 'k' && right != ' ' && right != '\n'){
                    right = getchar();
                    if (right == 'k' && right_rocket != 1){
                        right_rocket--;
                    }else if (right == 'm' && right_rocket != 23)
                    {
                        right_rocket ++;
                    }
                }
                nap_gor = 1;
            }
            if (who == 'r'){
                while (right != 'k' && right != 'm' && right != ' ' && right != '\n'){
                    right = getchar();
                    if (right == 'k' && right_rocket != 1){
                        right_rocket --;
                    }else if (right == 'm' && right_rocket != 23)
                    {
                        right_rocket --;
                    }
                }
                while (left != 'a' && left != 'z' && left != ' ' && left != '\n'){
                    left = getchar();
                    if (left == 'a' && left_rocket != 1){
                        left_rocket --;
                    }else if (left == 'z' && left_rocket != 23)
                    {
                        left_rocket ++;
                    }
                }
                nap_gor = -1;                          
            }