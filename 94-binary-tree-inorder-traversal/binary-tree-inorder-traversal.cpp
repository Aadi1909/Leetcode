class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> answer;
        while (node != nullptr || !st.empty()) {
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            answer.push_back(node->val);
            node = node->right;
        }
        return answer;
    }
};
