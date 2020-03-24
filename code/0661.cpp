class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int len1 = M.size();
        int len2 = M[0].size();
        vector<vector<int>> res(len1, vector<int>(len2, -1));
        // 该二维数组用于下标范围是否存在的遍历
        vector<vector<int>> indexs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int sum = 0;
                int cnt = 0;
                for (auto index : indexs) {
                    int m = i + index[0];
                    int n = j + index[1];
                    // 排除掉不能计算的下标
                    if (m < 0 || m >=len1 || n < 0 || n >= len2) {
                        continue;
                    }
                    sum += M[m][n];
                    cnt++;
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
//         int len1 = M.size();
//         int len2 = M[0].size();
//         vector<vector<int>> res(len1, vector<int>(len2, -1));

//         for (int i = 0; i < len1; i++) {
//             for (int j = 0; j < len2; j++) {
//                 int sum = 0;
//                 int cnt = 0;
//                 // 9个点从M中如果能够取出就加和
//                 if ((i - 1 >= 0 && i - 1 <= len1 - 1) && (j - 1 >=0 && j - 1 <= len2 - 1)) {
//                     sum += M[i - 1][j - 1];
//                     cnt++;
//                 }
//                 if ((i - 1 >= 0 && i - 1 <= len1 - 1) && (j >=0 && j <= len2 - 1)) {
//                     sum += M[i - 1][j];
//                     cnt++;
//                 }
//                 if ((i - 1 >= 0 && i - 1 <= len1 - 1) && (j + 1 >=0 && j + 1 <= len2 - 1)) {
//                     sum += M[i - 1][j + 1];
//                     cnt++;
//                 }

//                 if ((i >= 0 && i <= len1 - 1) && (j - 1 >=0 && j - 1 <= len2 - 1)) {
//                     sum += M[i][j - 1];
//                     cnt++;
//                 }
//                 if ((i >= 0 && i <= len1 - 1) && (j >=0 && j <= len2 - 1)) {
//                     sum += M[i][j];
//                     cnt++;
//                 }
//                 if ((i >= 0 && i <= len1 - 1) && (j + 1 >=0 && j + 1 <= len2 - 1)) {
//                     sum += M[i][j + 1];
//                     cnt++;
//                 }

//                 if ((i + 1 >= 0 && i + 1 <= len1 - 1) && (j - 1 >=0 && j - 1 <= len2 - 1)) {
//                     sum += M[i + 1][j - 1];
//                     cnt++;
//                 }
//                 if ((i + 1>= 0 && i + 1 <= len1 - 1) && (j >=0 && j <= len2 - 1)) {
//                     sum += M[i + 1][j];
//                     cnt++;
//                 }
//                 if ((i + 1>= 0 && i + 1<= len1 - 1) && (j + 1 >=0 && j + 1 <= len2 - 1)) {
//                     sum += M[i + 1][j + 1];
//                     cnt++;
//                 }
//                 res[i][j] = sum / cnt;
//             }
//         }
//         return res;
//     }
// };