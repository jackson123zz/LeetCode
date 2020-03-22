class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            hashMap[nums[i]]++;
        }
        for (auto m : hashMap) {
            if (m.second > 1) {
                return m.first;
            }
        }
        return -1;
    }
};