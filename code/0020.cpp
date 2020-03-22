/*
1、重点是判断14行的mStack为空，防止“)]”场景，mStack无法输入数据导致未空，最终判断出错。
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> mStack;
		for (int i = 0; i < (int)s.size(); i++) {
			if (mStack.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{') {
				mStack.push(s[i]);
			} else {
				if ((s[i] == ')' && mStack.top() == '(') || (s[i] == ']' && mStack.top() == '[') || (s[i] == '}' && mStack.top() == '{')) {
					mStack.pop();
				} else {
					break;
				}
			}
		}

		if (mStack.empty()) {
			return true;
		} else {
			return false;
		}
	}
};