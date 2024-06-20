class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<int> st;
        int n = a.size();
        vector<int> res(n, 0);
        st.push(n-1);
        for(int i = n-2; i >= 0; --i){
            while(!st.empty() and a[st.top()] <= a[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;

    }
};