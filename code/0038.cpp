#include <iostream>
#include <string>
using namespace std;
/*
 * 1. 递归实现，利用前一个字符串
 * 2. 使用C++的to_string函数，把数字转换为字符串
 *
*/
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        else {
            string s = countAndSay(n - 1);
            char temp = '0'; // 存储相同字符
            int num = 1;     // 存储相同字符个数
            string result = "";
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != s[i + 1]) {
                    temp = s[i];
                    result += to_string(num) + temp;
                    num = 1;
                }
                else {
                    num++;
                }
            }
            return result;
        }
    }
};

int main()
{
    int n = 3;
    Solution A;
    string result = A.countAndSay(n);
    cout << result << endl;;
}