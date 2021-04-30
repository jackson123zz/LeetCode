#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int pre = 0;
        int maxNum = nums[0];
        for (const auto &num : nums) {
            pre = max(pre + num, num);
            maxNum = max(maxNum, pre);
        }
        return maxNum;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution A;
    int result = A.maxSubArray(nums);
    cout << "result = " << result << endl;
}

