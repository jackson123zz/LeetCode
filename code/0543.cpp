/*
算法：
1、遍从某节点出发路过节点数M：左子树最大节点数 + 右子树最大节点数 + 1，路径为M-1
2、定义一个res值存储每个节点的最大路径长度， 
3、递归遍历每一个左右子树获取最大节点深度，左右取大
*/
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
    int res;
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int L = dfs(root->left);
        int R = dfs(root->right);
        res = max(res, L + R + 1);
        return max(L, R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 1;
        dfs(root);
        return res - 1;
    }
};