int lengthOfLastWord(char * s){

    int flag = 0;
    int num = 0;

    // Encontrando o tamanho do array
    while(s[flag] != '\0'){
        flag++;
    }

    // Percorrendo o array ao contrário para encontrar a última posição diferente de ' '
    flag -= 1;
    while(s[flag] == ' '){
        flag--;
    }


    // Percorrendo o array ao contrário a partir da última posição diferente de ' ' até encontrar um ' '.
    while(s[flag] != ' '){
        num++;
        flag--;
        // Condição especial para os casos em que o array consiste de uma única palavra
        if(flag < 0 ){
            return num;
        }
    }

    return num;
}  