/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int answer = 0;
    int f(TreeNode* node) {
        int lh = 0, rh = 0;
        if (node->left != nullptr) {
            lh = f(node->left);
        }
        if (node->right != nullptr) {
            rh = f(node->right);
        }
        answer = max(answer, lh + rh);
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int a = f(root);
        return answer;
    }
};