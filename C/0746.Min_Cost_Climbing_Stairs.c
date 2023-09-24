int min(int a, int b){
    // Função que retorna o menor valor entre dois inteiros
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int minCostClimbingStairs(int* cost, int costSize){
    
    // Percorrendo o array do fim ao iníco e armazenando dentro de cada posição o custo mínimo para chegar
    // no último degrau
    for(int i = costSize-3; i>=0; i--){
        cost[i]  += min(cost[i+1], cost[i+2]);
    }

    // Retornando o custo mínimo das duas posições possíveis de início
    return min(cost[0], cost[1]);
}