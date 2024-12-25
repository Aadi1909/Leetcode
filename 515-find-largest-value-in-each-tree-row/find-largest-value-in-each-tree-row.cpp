class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        vector<int> answer;
        answer.push_back(root->val);
        while (!st.empty()) {
            pair<TreeNode*, int> pair = st.top();
            st.pop();
            TreeNode* node = pair.first;
            int depth = pair.second;
            if (depth == answer.size()) {
                answer.push_back(node->val);
            }
            else {
                answer[depth] = max(answer[depth], node->val);
            }
            if (node->left) {
                st.push({node->left, depth + 1});
            }
            if (node->right) {
                st.push({node->right, depth + 1});
            }

        }
        return answer;
    }
};