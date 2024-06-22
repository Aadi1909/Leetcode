class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st1, st2;
        for(int i = popped.size() - 1; i >= 0; --i){
            st2.push(popped[i]);
        }
        for(int i = 0; i < pushed.size(); ++i){
            st1.push(pushed[i]);
            while(!st1.empty() and st1.top() == st2.top()){
                st1.pop();
                st2.pop();
            }
        }
        bool answer = (st1.size() + st2.size() > 0 ? false : true);
        return answer;
    }
};