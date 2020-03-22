/*
算法：
1、遍历数组2中的元素，然后依次遍历数组1中的元素，如果2中元素<1中元素，插入到改元素的前面
2、删除数组1中m+n以后的多余元素
*/
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int max = INT_MAX;
//         nums1.insert(nums1.begin() + m, max);
//         for (int i = 0; i < nums2.size(); i++) {
//             for (int j = 0; j < nums1.size(); j++) {
//                 if (nums2[i] < nums1[j]) {
//                     nums1.insert(nums1.begin() + j, nums2[i]);
//                     break;
//                 }
//             }
//         }
//         // 清除m+n之後的元素
//         nums1.erase(nums1.begin() + m + n, nums1.end());
//     }
// };

/*
算法：
1、把数组2加入到数组1中，然后sort排序
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m, j = 0; i < nums1.size(), j < nums2.size(); i++, j++) {
                nums1[i] = nums2[j];
            }
        sort(nums1.begin(), nums1.end());
    }
};