/*
1、获取vector的长度，进而得到n的值
2、遍历1~n，依次查找数是否在vector中，如果不在则返回
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        //vector<int>::iterator it = find()
        for (int i = 0; i <= n; i++) {
            if (find(nums.begin(), nums.end(), i) == nums.end()) {
                return i;
            }
        }
        return -1;
    }
};