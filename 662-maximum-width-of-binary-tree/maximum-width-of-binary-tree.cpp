typedef int long long ;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int answer = 0;
        while(!q.empty()){
            int sz = q.size();
            int idx = q.front().second;
            for(int i = 0; i < sz; ++i){
                int a = 0, b = 0;
                TreeNode* node = q.front().first;
                int index = q.front().second - idx; q.pop();
                if(node->left != nullptr){
                    q.push({node->left, (long long) 2 * index});
                }
                if(node->right != nullptr){
                    q.push({node->right, (long long) 2 * index + 1});
                }
                if(i == 0){
                    a = index;
                }
                if(i == sz - 1){
                    b = index;
                }
                answer = max(answer, b - a + 1);
            }
        }
        return answer;
    }
};