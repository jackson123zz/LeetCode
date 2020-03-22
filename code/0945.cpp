/*
算法：
1、把数组存储到一个map中，个数作为值，用来判断后续是否数目唯一
2、遍历map，如果个数>1,进行自增知道满足唯一条件插入到map中，记录自增次数
*/
// class Solution {
// public:
//     int minIncrementForUnique(vector<int>& A) {
//         unordered_map<int, int> hashMap= {};
//         int cnt = 0;
//         for (int i = 0; i < A.size(); i++) {
//             hashMap[A[i]]++;
//         }
//         for (auto m : hashMap) {
//             while (m.second > 1) {
//                 int tmp = m.first;
//                 do {
//                     tmp++;
//                     cnt++;
//                 } while (hashMap.find(tmp) != hashMap.end());
//                 hashMap[tmp]++;
//                 m.second--;
//             }
//         }
//         return cnt;
//     }
// };

/*
算法：
1、数组排序从小到大
2、转换思路：从某个重复的数平摊到数组中所有的数，遍历每一个数字，后面一个如果小于等于前面一个，就加到前面的数字+1，
加的次数作为最终的统计次数保存起来直到数组从无重复数字且有序
*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int cnt = 0;
        sort(A.begin(), A.end());
        for (int i = 1; i < A.size(); i++) {
            if (A[i] <= A[i - 1]) {
                int tmp = A[i];
                A[i] = A[i - 1] + 1;
                cnt += A[i] - tmp;
            }
        }
        return cnt;
    }
};