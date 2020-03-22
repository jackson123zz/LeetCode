/*
算法2：
1、新增两个hashMap，一个用于存储数组元素的出现累计次数，一个用于存储数组元素的首末位置，位置差+1即为连续最短子数组长度
2、遍历数组，填充hashMap1，如果数组元素第一次出现，hashMap新设置收尾位置，否则只更新末尾位置，设置max变量存储度，于hashMap.second循环比较
3、遍历hashMap1，如果元素出现次数为数组的度max，则获取该元素对应的hashMap2的second值进行做差，设置min存储最短的差值最后返回
方法：
pair()
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = 0;
        int res = INT_MAX;
        unordered_map<int, int> hashMap1;
        unordered_map<int, pair<int, int>> hashMap2;
        for (int i = 0; i < nums.size(); i++) {
            hashMap1[nums[i]]++;
            if (hashMap1[nums[i]] == 1) {
                hashMap2[nums[i]] = {i, i};
            } else {
                hashMap2[nums[i]].second = i;
            }
            degree = max(degree, hashMap1[nums[i]]);
        }
        for (auto m : hashMap1) {
            if (m.second == degree) {
                res = min(res, (hashMap2[m.first].second - hashMap2[m.first].first + 1));
            }
        }
        return res;
    }
};

/*
算法：
1、新增函数计算数组的度，并返回值
2、新增一个临时vector<int>用于遍历原数组的所有连续子数组，依次插入原数组数据，如果度满足要求，记录下长度保存为min变量（用于最后返回）
3、如果当前遍历度已经满足要求，不再继续遍历，应为长度肯定会比当前的长无意义
方法：
vector.clear()  --清空
vector.erase()  --删除某一个元素
*/
// class Solution {
//     int calDu(vector<int>& nums) {
//         unordered_map<int, int> hashMap;
//         int maxValue = 0;
//         for (int i : nums) {
//             hashMap[i]++;
//         }
//         for (auto m : hashMap) {
//             if (m.second > maxValue) {
//                 maxValue = m.second;
//             }
//         }
//         return maxValue;
//     }
// public:
//     int findShortestSubArray(vector<int>& nums) {
//         int minLen = 99999;
//         int len = 0;
//         vector<int> tmp = {};
//         int numsDu = calDu(nums);
//         for (int i = 0; i < nums.size(); i++) {
//             tmp.clear();
//             for (int j = i; j < nums.size(); j++) {
//                 tmp.push_back(nums[j]);
//                 if (calDu(tmp) == numsDu) {
//                     len = tmp.size();
//                     break;
//                 }
//             }
//             if (len < minLen) {
//                 minLen = len;
//             }
//         }
//         return minLen;
//     }
// };