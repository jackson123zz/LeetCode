/*
算法：
1、遍历数组2，然后再遍历数组1，如果数组1有和数组2中数字相等的置换到开头，index自增，遍历完后数组1和数组2保持相对顺序
2、然后对遍历后的index到end进行sort排序即可
方法：
排序常用方法：
1、swap交换
2、sort的使用algo
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int index = 0;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr1[j] == arr2[i]) {
                    swap(arr1[index], arr1[j]);
                    index++;
                }
            }
        }
        sort(arr1.begin() + index, arr1.end());
        return arr1;
    }
};