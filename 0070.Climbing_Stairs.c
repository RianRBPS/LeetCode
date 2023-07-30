int climbStairs(int n){
    
    //fibonacci
    int j = 1, k = 0;
    int possibilities;

    for(int i = 0; i < n; i++){
        possibilities = j + k;
        j = possibilities;
        k = j - k;
    }

    return possibilities;
}