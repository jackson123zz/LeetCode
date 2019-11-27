#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> hashMap;
		for (int i = 0; i < nums.size(); i++) {
			hashMap[nums[i]]++;
		}

		for (auto it : hashMap) {
			if (it.second == 1) {
				return it.first;
			}
		}
	}
};

/*
异或运算：
1、任意数字异或其本身为0, 1^1=0;
2、任意数字异或0为其本身， 1^0=1;
3、异或与顺序无关
*/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < nums.size(); i++) {
			result ^= nums[i];
		}
		return result;
	}
};