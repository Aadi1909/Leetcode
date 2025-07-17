class Solution {
public:
    vector<vector<int>> dp;
    int n;
    string s;

    int sol(int idx, int cnt) {
        if (cnt < 0 || cnt > n) return 0;
        if (idx == n) return cnt == 0;

        if (dp[idx][cnt] != -1) return dp[idx][cnt];

        if (s[idx] == '(')
            return dp[idx][cnt] = sol(idx + 1, cnt + 1);
        if (s[idx] == ')')
            return dp[idx][cnt] = sol(idx + 1, cnt - 1);

        return dp[idx][cnt] = sol(idx + 1, cnt + 1)
                            || sol(idx + 1, cnt - 1)
                            || sol(idx + 1, cnt);
    }

    bool checkValidString(string str) {
        s = str;
        n = s.length();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return sol(0, 0);
    }
};
