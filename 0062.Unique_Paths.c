#include <stdio.h>
#include <limits.h> // INT_MAX

/*
int fatorial(int x){
    if(x == 1){
        return 1;
    }else{
        return(x*fatorial(x-1));
    }
}


unsigned long long int fatorial(int x) {
    unsigned long long int resultado = 1;
    for (int i = 2; i <= x; i++) {
        resultado *= i;
        // Verificar e tratar caso de overflow
        if (resultado < 0) {
            // Tratar o overflow de acordo com a sua lógica
            // Por exemplo, retornar um valor especial ou lançar um erro
            return -1; // Ou outro valor apropriado
        }
    }
    return resultado;
}


unsigned long long int coeficienteBinomial(int N, int k) {
    
     // Arranjo combinatório 
    // A fórmula geral para calcular o coeficiente binomial (também conhecido como combinações) é:
    // C(n, k) = n! / (k! * (n - k)!)
    // Onde:
    // n é o número total de elementos.
    // k é o número de elementos que você deseja escolher.
    
    // Usar 'unsigned long long int' para armazenar os fatoriais
    unsigned long long int fatorialN = fatorial(N);
    unsigned long long int fatorialK = fatorial(k);
    unsigned long long int fatorialNK = fatorial(N - k);
    
    if (fatorialN == -1 || fatorialK == -1 || fatorialNK == -1) {
        // Tratar casos de overflow
        return -1; // Ou outro valor apropriado
    }
    
    return fatorialN / (fatorialK * fatorialNK);
}
*/

unsigned long long int coeficienteBinomial(int N, int k) {
    
    // Aplicando a fórmula de Pascal para reduzir a complexidade do coeficiente binomial
    // C(n, k) = C(n-1, k-1) + C(n-1, k)
    
    // Tratamento especial para o caso N = k ou k = 0
    if (k == 0 || N == k) {
        return 1;
    }
    
    // Usar 'unsigned long long int' para evitar estouro
    unsigned long long int resultado = 1;
    
    // Calcular C(N, k) usando a fórmula de Pascal
    if (k < N - k) {
        k = N - k; // O coeficiente binomial é simétrico, então calcular o oposto é mais eficiente.
    }
    
    for (int i = 1; i <= k; i++) {
        resultado *= (N - k + i);
        resultado /= i;
    }
    
    return resultado;
}

int uniquePaths(int m, int n){
    
    // Quantas vezes o robo precisa obrigatoriamente descer
    int down = m - 1;
    
    // Quantas vezes o robo precisa obrigatoriamente ir para a direita
    int right = n - 1;
    
    // Total de movimentos que o robo ira realizar
    int totalmoves = down + right;
    
    // O robo ira sempre precisar realizar uma combinação de A "down" descidas e B "right" passos para a direita
    // Assim, iremos calcular C(N, A) * C(N - A, B)
    // Isso nós dará o número total de arranjos possíveis de tamanho N, levando em consideração a repetição de elementos "down" e "right".
    
    unsigned long long int Ca = coeficienteBinomial(totalmoves, down);
    unsigned long long int Cb = coeficienteBinomial(totalmoves - down, right);
    
    if (Ca == -1 || Cb == -1) {
        // Tratar casos de overflow
        return -1; // Ou outro valor apropriado
    }
    
    // Verificar se o resultado cabe em 'int' antes de retornar
    unsigned long long int resultado = Ca + Cb - 1;
    if (resultado > INT_MAX) {
        return -1; // Ou outro valor apropriado
    }
    
    return (int)resultado;
    
}