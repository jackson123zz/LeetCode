class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxValue= INT_MIN;
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                tmp++;
            } else {
                maxValue = max(maxValue, tmp);
                tmp = 0;
            }
        }
        maxValue = max(maxValue, tmp);
        return maxValue;
    };
};