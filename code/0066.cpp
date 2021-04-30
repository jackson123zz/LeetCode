#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    vector<int> plusOne(vector<int>& digits) {
//        long num = 0;
//        for (int i = 0; i < digits.size(); i++) {
//            num = num * 10 + digits[i];
//        }
//        num += 1;
//        vector<int> out;
//        while (num) {
//            out.push_back(num % 10);
//            num /= 10;
//        }
//        reverse(out.begin(), out.end());
//        return out;
//    }
//};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += 1;
            if (digits[i] == 10) {
                digits[i] = 0;
            }
            else {
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    vector<int> digits = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
    Solution A;
    vector<int> result = A.plusOne(digits);
    std::cout << "result is \n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
}