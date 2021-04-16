#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};

int main()
{
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    Solution A;
    int len = A.removeDuplicates(nums);
    std::cout << "len = " << len << endl;
    for (int i = 0; i < len; i++) {
        cout << nums[i];
    }
    cout << endl;
}