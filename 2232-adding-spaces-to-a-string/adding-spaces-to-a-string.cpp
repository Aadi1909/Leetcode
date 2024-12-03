class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer = "";
        deque<int> dq(spaces.begin(), spaces.end());
        for (int i = 0; i < s.length(); ++i) {
            if (dq.front() == i) {
                answer += ' ';
                dq.pop_front();
            }
            answer += s[i];
        }
        return answer;
    }
};