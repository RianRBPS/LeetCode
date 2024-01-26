// 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
    // Definindo a função findPaths que retorna o número de caminhos para mover uma bola
    // para fora de uma grade de tamanho m x n, começando da posição (startRow, startColumn)
    // e com um número máximo de movimentos maxMove.
    fun findPaths(m: Int, n: Int, maxMove: Int, startRow: Int, startColumn: Int): Int {
        val mod = 1000000007 // Definindo um valor para aplicar o módulo e evitar overflow

        // Criando um array tridimensional para armazenar a contagem de caminhos.
        // dp[i][j][k] armazena o número de caminhos para chegar à célula (i, j) em k movimentos.
        val dp = Array(m) { Array(n) { LongArray(maxMove + 1) { 0 } } }

        // Definindo as direções possíveis de movimento (cima, baixo, esquerda, direita).
        val dirs = arrayOf(intArrayOf(-1, 0), intArrayOf(1, 0), intArrayOf(0, -1), intArrayOf(0, 1))

        // Inicializando a posição inicial com 1 caminho para 0 movimentos.
        dp[startRow][startColumn][0] = 1

        // Variável para armazenar o resultado final (número total de caminhos para sair da grade).
        var result = 0L 

        // Loop para cada movimento, de 1 até maxMove.
        for (move in 1..maxMove) {
            // Iterando sobre cada célula da grade.
            for (i in 0 until m) {
                for (j in 0 until n) {
                    // Iterando sobre cada direção possível de movimento.
                    for (dir in dirs) {
                        // Calculando as novas coordenadas após o movimento.
                        val ni = i + dir[0]
                        val nj = j + dir[1]

                        // Checando se as novas coordenadas estão dentro da grade.
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            // Atualizando o número de caminhos para chegar à célula atual em 'move' movimentos.
                            dp[i][j][move] = (dp[i][j][move] + dp[ni][nj][move - 1]) % mod
                        } else {
                            // Se a célula estiver fora da grade, atualize o resultado com os caminhos de saída.
                            result = (result + dp[i][j][move - 1]) % mod
                        }
                    }
                }
            }
        }
        
        // Retornando o resultado final (convertido para Int).
        return result.toInt()
    }
}
