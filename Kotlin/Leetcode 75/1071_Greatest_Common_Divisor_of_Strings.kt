// 1071 Greatest Common Divisor of Strings
// https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75

class Solution {
    fun gcdOfStrings(str1: String, str2: String): String {
        // Função para encontrar o maior divisor comum de dois números
        fun mdc(a: Int, b: Int): Int {
            if(b == 0) return a
            return mdc(b, a % b)
        }
        // Testando se concatenar str1 e str2 em qualquer ordem resulta na mesma string
        if(str1 + str2 != str2 + str1) return ""
        
        // Encontrando o MDC dos tamanhos de str1 e str2
        val mdcLength = mdc(str1.length, str2.length)
        
        // Retornar a substring de str1 de 0 para mdcLenght
        return str1.substring(0, mdcLength)
    }
}

// Example usage
fun main() {
    println(gcdOfString("ABCABC", "ABC"))   // Output: "ABC"
    println(gcdOfString("ABABAB", "ABAB")) // Output: "AB"
    println(gcdOfString("LEET", "CODE"))   // Output: ""
}
