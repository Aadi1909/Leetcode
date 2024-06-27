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
    vector<int> answer;
    void f(TreeNode* root) {
        if(root == nullptr){
            return ;
        }
        f(root->left);
        f(root->right);
        answer.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        f(root);
        return answer;
    }
};