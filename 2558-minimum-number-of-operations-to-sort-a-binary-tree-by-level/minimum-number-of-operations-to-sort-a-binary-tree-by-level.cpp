class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int oper = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> e;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) {
                    q.push(node->left);
                    e.push_back(node->left->val);
                }
                if (node->right) {
                    q.push(node->right);
                    e.push_back(node->right->val);
                }
            }
            if (e.empty()) continue;
            vector<int> sorted_e = e;
            sort(sorted_e.begin(), sorted_e.end());
            unordered_map<int, int> pos;
            for (int i = 0; i < sorted_e.size(); ++i) {
                pos[sorted_e[i]] = i;
            }
            vector<bool> visited(e.size(), false);
            for (int i = 0; i < e.size(); ++i) {
                if (visited[i] or pos[e[i]] == i) continue;
                int cycle_size = 0;
                int x = i;
                while (!visited[x]) {
                    visited[x] = true;
                    x = pos[e[x]];
                    cycle_size++;
                }
                if (cycle_size > 1) {
                    oper += cycle_size - 1;
                }
            }
        }
        return oper;
    }
};
