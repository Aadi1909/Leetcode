class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stack;
        int partLen = part.length();
        for (char ch : s) {
            stack += ch;
            if (stack.size() >= partLen && stack.substr(stack.size() - partLen) == part) {
                stack.erase(stack.size() - partLen);
            }
        }
        return stack;
    }
};
