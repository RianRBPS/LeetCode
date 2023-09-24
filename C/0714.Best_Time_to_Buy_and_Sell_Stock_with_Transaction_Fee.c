// Link do problema
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/3670801/pure-c-simple-solution/

#include <stdio.h>

// Pq define?
// Pq "?" e ":" ?
#define MAXIMO(a, b) (((a) > (b)) ? (a) : (b))

int maxProfit(int* prices, int pricesSize, int fee){
    int lucroAtual = -prices[0];
    int lucro = 0;

    int i = 0;
    while(i<pricesSize){
        lucroAtual = MAXIMO(lucroAtual, lucro - prices[i]);
        lucro = MAXIMO(lucro, lucroAtual + prices[i] - fee);
        i++;
    }

    return lucro;
}