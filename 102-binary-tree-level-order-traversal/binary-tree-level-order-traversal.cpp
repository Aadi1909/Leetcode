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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == nullptr) {
            return answer;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            vector<int> values;
            int sz = Q.size();
            for (int i = 0; i < sz; ++i){
                TreeNode* node = Q.front(); Q.pop();
                values.push_back(node->val);
                if(node->left != nullptr) Q.push(node->left);
                if(node->right != nullptr) Q.push(node->right);
            }
            answer.push_back(values);
        }
        return answer;
    }
};