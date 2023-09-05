int minimo(int a, int b){
    return a < b? a : b;
}

int minExtraChar(char * s, char ** dictionary, int dictionarySize){

    // Size of s
    int n = strlen(s);

    // dp[i] represents the minimum number of extra characters up to index i
    int dp[n+1];

    // Initiliazing the first element of the dp array with 0 because no extra characters are needed to construct an empty string 
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1] + 1; // Initialize with one more extra character than the previous index

            for (int j = 0; j < dictionarySize; j++) {
                int len = strlen(dictionary[j]);
                if (i >= len && strncmp(s + i - len, dictionary[j], len) == 0) {
                    dp[i] = minimo(dp[i], dp[i - len]);  // If we can form a word from dictionary, update dp[i]
                }
        }
    }

    return dp[n];
}
