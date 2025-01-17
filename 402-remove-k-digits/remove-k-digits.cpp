class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string result;
        for (char digit : num) {
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);
        return result.empty() ? "0" : result;
    }
};
