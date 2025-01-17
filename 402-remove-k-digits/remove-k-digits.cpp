class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";
        int n = num.length();
        stack<char> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && k > 0 && stk.top() > num[i]) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }
        string answer;
        while (!stk.empty()) {
            answer.push_back(stk.top());
            stk.pop();
        }
        reverse(answer.begin(), answer.end());
        while (!answer.empty() && answer[0] == '0') {
            answer.erase(answer.begin());
        }

        return answer.empty() ? "0" : answer;
    }
};
