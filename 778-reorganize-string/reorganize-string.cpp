class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        priority_queue<pair<int, char>> pq;
        int maxFreq = 0, n = s.length();
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                pq.push({freq[i], 'a' + i});
                maxFreq = max(maxFreq, freq[i]);
            }
        }
        if (maxFreq > (n + 1) / 2) return "";
        string answer(n, ' ');
        int index = 0;
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            while (count--) {
                if (index >= n) index = 1;
                answer[index] = ch;
                index += 2;
            }
        }
        return answer;
    }
};