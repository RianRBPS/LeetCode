#include <stdio.h>
#include <limits.h>

int minTaps(int n, int* ranges, int rangesSize){

    // minimum number -> Greedy Algorithm
    // Greedy Algorithm - an algorithmic paradigm that follows the problem solving approach of making the locally optimal choice at each stage with the hope of finding a global optimum
    // Pros - simple, easy to implement, run fast
    // Cons - very often they don't provide a globally optimum solution

    // Assuming user calls free
    int* dp = (int*)malloc(sizeof(int)*(n+1));
    
    for(int i = 0; i<=n; i++){
        // INT_MAX is a constant that represents the maximum value that can be held by an int data type. It is defined in the <limits.h> header, which is a standard C library header that provides various constants related to the limits of different data types.
        dp[i] = INT_MAX;
        //In the code above, the dp[i] variable is assigned the value of INT_MAX. This value might vary depending on the system and compiler you're using, but it's typically 2147483647, which is 2^31 - 1.
    } 

    dp[0] = 0;

    for(int i = 0; i <= n; i++){
        int left = i - ranges[i] > 0 ? i - ranges[i] : 0;
        int right = i + ranges[i] < n ? i + ranges[i] : n;

        for(int j = left; j <= right; j++){
            dp[j] = dp[j] < dp[left] + 1? dp[j] : dp[left] + 1;
        }
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
}

/*
Ternary Operator (? :):
The ternary operator is a shorthand way to write an if statement in a single line. It has the form:

    condition ? value_if_true : value_if_false;

*/

