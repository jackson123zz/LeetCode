#include <iostream>
#include <vector>

using namespace std;

/*
算法：
1、两次遍历获取车的行列值
2、遍历4次车的行列，计算每次的吃掉卒的数量最后相加
*/
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int len1 = board.size();
        int len2 = board[0].size();
        int m = 0;
        int n = 0;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (board[i][j] == 'R') {
                    m = i;
                    n = j;
                }
            }
        }
        //左边一次遍历
        int t1 = 0;
        for (int i = 0; i < m; i++) {
            if (board[i][n] == 'p') {
                t1++;
            } else if (board[i][n] == 'B') {
                t1 = 0;
            }
        }
        t1 = (t1 > 0) ? 1 : 0;

        // 右边一次遍历
        int t2 = 0;
        for (int i = len1 -1; i > m; i--) {
            if (board[i][n] == 'p') {
                t2++;
            } else if (board[i][n] == 'B') {
                t2 = 0;
            }
        }
        t2 = (t2 > 0) ? 1 : 0;

        int t3 = 0;
        for (int j = 0; j < n; j++) {
            if (board[m][j] == 'p') {
                t3++;
            } else if (board[m][j] == 'B') {
                t3 = 0;
            }
        }
        t3 = (t3 > 0) ? 1 : 0;

        int t4 = 0;
        for (int j = len2 - 1; j > n; j--) {
            if (board[m][j] == 'p') {
                t4++;
            } else if (board[m][j] == 'B') {
                t4 = 0;
            }
        }
        t4 = (t4 > 0) ? 1 : 0;
        return t1 + t2 + t3 + t4;
    }
};

int main() {
    cout << "hello world!" << endl;
    vector<vector<char>> board = {
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','R','.','.','.','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };
    Solution aa;
    int res = aa.numRookCaptures(board);
    cout << res << endl;
    return 0;
}