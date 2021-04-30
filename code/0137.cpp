#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        for (auto x : map) {
            if (x.second == 1) {
                return x.first;
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> num = { 0,1,0,1,0,1,99 };
    Solution A;
    int result = A.singleNumber(num);
    std::cout << "result = " << result << endl;;
}

