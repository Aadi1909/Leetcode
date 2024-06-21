class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = mxArea(heights);
        return res;
    }
    
    int mxArea(vector<int> &a) {
        int n = a.size();
        vector<int> li(n), ri(n);
        
        stack<int> st1, st2;
        st1.push(n - 1);
        ri[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            while (!st1.empty() && a[st1.top()] >= a[i]) {
                st1.pop();
            }
            if (st1.empty()) {
                ri[i] = n;
            } else {
                ri[i] = st1.top();
            }
            st1.push(i);
        }
        
        st2.push(0);
        li[0] = -1;
        for (int i = 1; i < n; i++) {
            while (!st2.empty() && a[st2.top()] >= a[i]) {
                st2.pop();
            }
            if (st2.empty()) {
                li[i] = -1;
            } else {
                li[i] = st2.top();
            }
            st2.push(i);
        }
        
        int maxarea = -1;
        for (int i = 0; i < n; i++) {
            int width = ri[i] - li[i] - 1;
            int area = width * a[i];
            maxarea = max(maxarea, area);
        }
        
        return maxarea;
    }
};