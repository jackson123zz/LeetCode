/*
算法：
1、动态规划，利于局部最优解得出最后的最优解
dp[i] = dp[i-1] + dp[i-2]
方法：
1、注意前面加判断，否则dp[1]当n为1时会越界，出现heap-buffer-overflow error
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};