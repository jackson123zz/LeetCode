#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        int maxSize = max(a.size(), b.size());
        for (int i = 0; i < maxSize; i++) {
            carry += (i < a.size() ? (a.at(i) == '1') : 0);
            carry += (i < b.size() ? (b.at(i) == '1') : 0);
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};

int main()
{
    string a = "1010", b = "1011";
    Solution A;
    string result = A.addBinary(a, b);
    std::cout << "result = " << result << std::endl;
}
