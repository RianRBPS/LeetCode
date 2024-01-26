// 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
    fun findPaths(m: Int, n: Int, maxMove: Int, startRow: Int, startColumn: Int): Int {
        val mod = 1000000007
        val dp = Array(m) { Array(n) { LongArray(maxMove + 1) { 0 } } }
        val dirs = arrayOf(intArrayOf(-1, 0), intArrayOf(1, 0), intArrayOf(0, -1), intArrayOf(0, 1))
        dp[startRow][startColumn][0] = 1
        var result = 0L

        for (move in 1..maxMove) {
            for (i in 0 until m) {
                for (j in 0 until n) {
                    for (dir in dirs) {
                        val ni = i + dir[0]
                        val nj = j + dir[1]
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            dp[i][j][move] = (dp[i][j][move] + dp[ni][nj][move - 1]) % mod
                        } else {
                            result = (result + dp[i][j][move - 1]) % mod
                        }
                    }
                }
            }
        }
        
        return result.toInt()
    }
}
