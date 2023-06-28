#include <stdio.h>

int romanToInt(char * s){

    int num = 0;
    int i = 0;

    while(s[i] != '\0');{
        switch (s[i]){
            case 'M':
                if(s[i-1] == 'C'){
                    num += 900;
                }else{
                    num += 1000;
                }

            case 'D':
                if(s[i-1] == 'C'){
                    num += 400;
                }else{
                    num += 500;
                }
 
            case 'C':
                if(s[i+1] == 'M' || s[i+1] == 'D'){
                    break;
                }else{
                    if(s[i-1] == 'X'){
                        num+=90;
                    }else{
                        num+= 100;
                    }
                }
            
            case 'L':
                if(s[i-1] == 'X'){
                    num += 40;
                }else{
                    num += 50;
                }

            case 'X':
                if(s[i+1] == 'L' || s[i+1] == 'C'){
                    break;
                }else{
                    if(s[i-1] == 'I'){
                        num += 9;
                    }else{
                        num += 10;
                    }
                }


            case 'V':
                if(s[i-1] == 'I'){
                    num += 4;
                }else{
                    num += 5;
                }


            case 'I':
                if(s[i+1] == 'V' || s[i+1] == 'X'){
                    break;
                }else{
                    num += 1;
                }
        }
        i++;
    }
    return num;
}

int main(){

    char s[3] = "XVI";

    int x = romanToInt(s);

    printf("%d", x);

    return 0;
}