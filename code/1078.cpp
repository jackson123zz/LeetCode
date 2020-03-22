/*
算法：
1、通过stringstream(<sstream>)对字符串按照空格进行分隔放到vector中
2、遍历这个vector，满足条件插入到返回的vector中，最后返回数据
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> input;
        vector<string> res;
        stringstream ss(text);
        string tmp;
        while (ss >> tmp) {
            input.push_back(tmp);
        }

        for (int i = 0; i < input.size(); i++) {
            if (input[i] == first && input[i + 1] == second && i + 2 < input.size()) {
                res.push_back(input[i + 2]);
            }
        }
        return res;

    }
};