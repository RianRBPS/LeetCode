#include <stdbool.h>

bool isPalindrome(int x){
    
    // Todo número menor que 0 não é palindromo, pois o sinal de "-" sempre ficara invertido
    if(x < 0){
        return false;
    }

    // Criando uma variável auxiliar recebendo o valor de x
    long aux = x;

    // Criando uma variável que irá receber o inverso de x
    long y = 0;

    // Percorrendo a variável x e atribuindo o resto da sua divisão por 10 para cada última cada de y, e então multiplicando y por 10 e divindido x por 10
    while(x != 0){
        y *= 10;
        y += x % 10;
        x -= x % 10;
        x /= 10;
    }

    // Como y é o inverso de aux, se o resto da divisão por 10 de y for diferente do resto da divisão por 10 de aux, o número não é um palindromo
    while(y>0){
        if( (y%10) != (aux%10) ){
            return false;
        }
        y -= y%10;
        y /= 10;
        aux -= aux%10;
        aux /= 10;
    }

    // Caso a variável y tenha passado pelo caso teste acima, ela já pode ser considerada um palindromo
    return true;
}