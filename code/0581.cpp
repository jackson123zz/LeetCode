/*
算法：
1、两次遍历，第一次如果后面元素小于前面元素，记下index1；第二次从后遍历，如果前面元素大于后面元素，记下index2,此时获取的是最小集合
[0,5,6,4,7,9,8] --首次下降从6开始，但是5会比6以后的区别内的4还要大，所以5也应该包含进来，因此需要从获得区间内选取最大最小值，
然后左边扩展到均小于最小值，右边扩展到均大于最大值即可
2、返回index2-index1+1
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int res = 0;
        int index1 = 0;
        int index2 = 0;
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[i]) {
                index1 = i;
                break;
            }
        }
        for (int j = nums.size() -2; j >= 0; j--) {
            if (nums[j] > nums[j + 1]) {
                index2 = j + 1;
                break;
            }
        }
        // 遍历区间，获取区间内最大最小值
        for (int i = index1; i <= index2; i++) {
            minValue = min(minValue, nums[i]);
            maxValue = max(maxValue, nums[i]);
        }

        for (int i = index1 - 1; i >=0; i--) {
            if (nums[i] <= minValue) {
                break;
            } else {
                index1 = i;
            }
        }

        for (int j = index2; j < nums.size(); j++) {
            if (nums[j] >= maxValue) {
                break;
            } else {
                index2 = j;
            }
        }
        return (index1 == index2) ? 0 : (index2 - index1 + 1);
    }
};