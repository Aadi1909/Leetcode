class Solution {
public:
    string result;

    void dfs(TreeNode* node, string& curr) {
        if (!node) return;
        curr.push_back('a' + node->val);
        if (!node->left && !node->right) {
            string temp = curr;
            reverse(temp.begin(), temp.end());
            if (result.empty() || temp < result) {
                result = temp;
            }
        }
        if (node->left) {
            dfs(node->left, curr);
        }
        if (node->right) {
            dfs(node->right, curr);
        }
        curr.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        result = "";
        string r;
        dfs(root, r);
        return result;
    }
};
