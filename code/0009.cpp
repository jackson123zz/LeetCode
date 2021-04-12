#include <iostream>

using namespace std;
/*
 * 判断回文数
 * 1、判断负数直接返回false
 * 2、数字对调后判断与原数字是否相等即可
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long newNum = 0;
        long tempNum = x;
        while (tempNum != 0) {
            newNum = newNum * 10 + tempNum % 10;
            tempNum = tempNum / 10;
        }
        return (x == newNum);
    }
};

int main() {
    int x = 1234567899;
    Solution A;
    bool result = A.isPalindrome(x);
    cout << "result is " << result << endl;
    return 0;
}