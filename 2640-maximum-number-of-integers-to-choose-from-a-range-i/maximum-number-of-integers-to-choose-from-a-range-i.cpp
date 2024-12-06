class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> st;
        for (int i = 1; i <= n; ++i) 
            st.insert(i);

        for (int& ban : banned) {
            st.erase(ban);
        }
        
        vector<int> a(st.begin(), st.end());
        int lo = 0, hi = a.size(), best = 0;

        while (lo <= hi) {
            int m = (lo + hi) / 2;
            long long sum = 0;

            for (int i = 0; i < m; ++i) {
                sum += a[i];
            }

            long long minsum = sum;
            int l = 0, r = m;

            while (r < a.size()) {
                sum -= a[l++];
                sum += a[r++];
                minsum = min(minsum, sum);
            }

            if (minsum <= maxSum) {
                best = m;
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }

        return best;
    }
};