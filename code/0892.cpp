/*
1、计算：多个立方体的表面积和，注意相邻格子间的贴合导致表面积减少的影响

*/
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int len1 = grid.size();
        int len2 = grid[0].size();
        int sum = 0;
        // 用于遍历4个表面
        vector<int> row = {0, 1, 0, -1};
        vector<int> column = {-1, 0, 1, 0};
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (grid[i][j] > 0) {
                    // 上下两个底面加上
                    sum += 2;
                    // 遍历四个册面
                    for (int m = 0; m < 4; m++) {
                        int r = i + row[m];
                        int c = j + column[m];
                        int nv = 0;
                        if (r >= 0 && r < len1 && c >= 0 && c < len2) {
                            nv = grid[r][c];
                        }
                        sum += max(grid[i][j] - nv, 0);
                    }
                }
            }
        }
        return sum;
    }
};