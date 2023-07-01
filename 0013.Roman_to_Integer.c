int romanToInt(char * s){
    
    // Tomar cuidado para que o array não esteja em uma posição negativa
    int num = 0;
    int i = 0;

    while(s[i] != '\0'){

        switch (s[i]){
            
            case 'M':
                if(i>0){
                    if(s[i-1] == 'C'){
                        num += 900;
                        break;
                    }else{
                        num += 1000;
                        break;
                    }
                }else{
                    num += 1000;
                    break;
                }


            case 'D':
                if(i>0){
                    if(s[i-1] == 'C'){
                        num += 400;
                        break;
                    }else{
                        num += 500;
                        break;
                    }
                }else{
                    num += 500;
                    break;
                }
            

            case 'C':
                if(i>0){
                    if(s[i-1] == 'X'){
                        num += 90;
                        break;
                    }else if(s[i+1] == 'M' || s[i+1] == 'D'){
                        break;
                    }else{
                        num += 100;
                        break;
                    }
                }else{
                    if(s[i+1] == 'M' || s[i+1] == 'D'){
                        break;
                    }else{
                        num += 100;
                        break;
                    }
                }


            case 'L':
                if(i>0){
                    if(s[i-1] == 'X'){
                        num += 40;
                        break;
                    }else{
                        num += 50;
                        break;
                    }
                }else{
                    num += 50;
                    break;
                }
            
            case 'X':
                if(i>0){
                    if(s[i-1] == 'I'){
                        num += 9;
                        break;
                    }else if(s[i+1] == 'L' || s[i+1] == 'C'){
                        break;
                    }else{
                        num += 10;
                        break;
                    }
                }else{
                    if(s[i+1] == 'L' || s[i+1] == 'C'){
                        break;
                    }else{
                        num += 10;
                        break;
                    }
                }
            
            case 'V':
                if(i>0){
                    if(s[i-1] == 'I'){
                        num += 4;
                        break;
                    }else{
                        num += 5;
                        break;
                    }
                }else{
                    num += 5;
                    break;
                }

            case 'I':
                if(s[i+1] == 'X' || s[i+1] == 'V'){
                    break;
                }else{
                    num++;
                    break;
                }

        }// Fim do switch case

        i++;
    }// Fim do while loop

    return num;
}// Fim da função