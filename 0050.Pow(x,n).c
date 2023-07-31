double myPow(double x, int n){

    unsigned int num = n;
    // Se n for nulo
    if(n == 0){
        return 1;
    }

    // Se n for negativo
    if(n<0){
        num = num * -1;
        x = 1.0 / x;
    }

    double resultado = 1;
    while(num){
        if(num%2 == 1){
            resultado = resultado * x;
            num-=1;
        }
        x *= x;
        num /= 2;
    }
    return resultado;
}
