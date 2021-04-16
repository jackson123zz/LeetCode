#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i]) {
                return i;
            } else if (target < nums[i]) {
                nums.insert(nums.begin() + i, target);
                return i;
            }
        }
        nums.push_back(target);
        return nums.size() - 1;
    }
};

int main()
{
    vector<int> nums = { 1,3,5,6 };
    int target = 0;
    Solution A;
    int result = A.searchInsert(nums, target);
    cout << "resutl = " << result << endl;
}