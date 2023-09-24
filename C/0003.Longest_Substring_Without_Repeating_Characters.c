#include <stdio.h>

int lengthOfLongestSubstring(char * s){

    // Tamanho da maior substring encontrada
    int lenght = 0;
    
    // aux aponta para o ínicio da string e será usado para percorrer a string
    char *aux = s;

    // temp é um ponteiro temporário que será utilizado para armazenar o endereço de um caractere duplicado na tabela de endereços
    char *temp;

    // Na tabela de enderecos iremos rastrear o endereço de cada caracter que aparece na string.
    // O tamanho da tabela é 128, assumindo que a string contém apenas caracteres ASCII (Valores de 0 a 127)
    // Inicialmente todos os elementos da tabela são definidos como NULL
    char *tabelaEnderecos[128] = {NULL};

    // O loop irá continuar até que *aux aponte para um caracter nulo '/0'
    while(*aux){

        // Obtém o endereço atual na tabela de endereços para o caracter apontado por *aux
        temp = tabelaEnderecos[*aux];

        // Atualiza o endereço do caractere atual na tabela de endereços com o endereço atual
        tabelaEnderecos[*aux] = aux;

        // Verifica se o endereço armazenado na tabela de endereços (temp) é maior ou igual ao início da string 's'
        // Se for, isso significa que o caracter atual já apareceu anteriormente em uma posição dentro da janela deslizante
        if(temp >= s){

            // Calcula o comprimento da substring atual (dese o início até o caractere atual) e compara com o valor de 'len'
            // Se o comprimento atual for maior que 'len', atualiza o valor de 'len' com o comprimento atual
            lenght = (aux - s) > lenght ? (aux -s): lenght;

            // Atualiza o início da janela deslizante para o pŕoximo caractere após o caractere duplicado encontrado na tabela de endereços
            // Isso garante que a janela deslizante não contenha caracteres repetidos
            s = temp + 1;
        }
        // Avança o ponteiro 'aux' para o pŕoximo caractere na string
        aux ++;
    }

    // Calcula novamente o comprimento da substring atual e compara com o valor de len
    // Se o comprimento atual for maior que 'len', atualiza o valor de 'len' com o caractere atual
    lenght = (aux - s) > lenght? (aux -s): lenght;

    // Retorna a o tamanho da maior substring encontrada
    return lenght;
}