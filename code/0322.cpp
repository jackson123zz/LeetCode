/*
算法：
1、暴力递归方法，状态转移方程为 dp[i] = min(dp[i], dp[i-coin])
*/
class Solution {
    int dp(vector<int>& memo, vector<int>& coins, int amount)
    {
        // base case
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }
        if (memo[amount] != 0) {
            return memo[amount];
        }
        int res = INT_MAX - 1;
        for (int i : coins) {
            int subAmount = dp(memo, coins, amount - i);
            if (subAmount < 0) {
                continue;
            }
            res = min(res, subAmount + 1);
        }
        // 避免res认为原始设置的默认值的场景下，返回一个INT_MAX错误，此时无可返回值应该返回-1
        if (res != INT_MAX - 1) {
            memo[amount] = res;
        } else {
            memo[amount] = -1;
        }

        return memo[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, 0);
        return dp(memo, coins, amount);
    }
};