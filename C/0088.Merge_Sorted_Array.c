void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

    // O valor i inicia na última posição diferente de zero do array nums1
    int i = m - 1;
    // O valor j inicia na última posição diferente de zero do array nums 2
    int j = n - 1;

    // Enquanto as poições i de nums1 e j de nums2 forem não nulas
    while(i>=0 && j>=0){
        // Se a o elemento atual (começando pelo m-1) de nums1 for maior que o elemento atual
        // de nums2 (começando pelo último), a posição [i+j+1] de nums1 receber o valor da posição
        // i de nums1
        // Obs:
        // A posição [i+j+1] é equivalente a m-1 + n-1 + 1, ou seja, na primeira iteração
        // ela ira corresponder a última posição real de nums1
        if(nums1[i] > nums2[j]){
            nums1[i+j+1] = nums1[i];
            i--;
        }else{
            // Se a posição atual j de nums2 for maior ou igual a posição atual i de nums1,
            // a posição [i+j+1] de nums1 ira receber o valor da posição nums2[j]
            nums1[i+j+1] = nums2[j];
            j--;
        }
    }

    // Caso a primeira iteração termine e j continue sendo maior ou igual a zero, ainda existem
    // elementos de nums2 que não foram percorridos, neste casos nós resta apenas inserir os elementos
    // de nums2 não percorridos dentro de nums1
    // É uma boa prática assumir que i sempre irá começar com o valor -1
    // Então, a posição [i+j-1] do array nums1 será sempre [-1+j+1], podemos simplificar então para
    // [j]
    while(j>=0){
        nums1[j] = nums2[j];
        j--;
    }
    
}