// 1431 Kids With the Greatest Number of Candies
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
    fun kidsWithCandies(candies: IntArray, extraCandies: Int): List<Boolean> {
        // Encontrar o número máximo de doces que qualquer criança atualmente possui
        val maxCandies = candies.maxOrNull() ?: 0
        
        // Criar um array de resultados para armazenar os valores booleanos
        val result = BooleanArray(candies.size)
        
        // Percorrer o array de doces
        for (i in candies.indices) {
            // Verificar se, aos dar extraCandies para a i-ésima criança, a quantidade total de doces
            // dela é maior ou igual ao máximo encontrado
            result[i] = candies[i] + extraCandies >= maxCandies
        }
        
        return result.toList()
    }
}

// Exemplo de uso
fun main() {
    println(kidsWithCandies(intArrayOf(2,3,5,1,3), 3).contentToString()) // [true, true, true, false, true]
    println(kidsWithCandies(intArrayOf(4,2,1,1,2), 1).contentToString()) // [true, false, false, false, false]
    println(kidsWithCandies(intArrayOf(12,1,12), 10).contentToString()) // [true, false, true]
}
