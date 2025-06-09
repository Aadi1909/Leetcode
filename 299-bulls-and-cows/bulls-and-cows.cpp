class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int, set<int>> mp1;
        unordered_map<int, pair<int, int>> mp2;            
        unordered_map<int, int> mp3; 
        for (int i = 0; i < secret.length(); ++i) {
            mp1[secret[i] - '0'].insert(i);
            mp3[secret[i] - '0']++;
        }
        int bulls = 0, cows = 0;
        for (int i = 0; i < guess.length(); ++i) {
            int digit = guess[i] - '0';
            if (mp1.find(digit) == mp1.end()) continue;

            if (mp1[digit].find(i) != mp1[digit].end()) {
                mp2[digit].first += 1;
            } else {
                mp2[digit].second += 1; 
            }
        }

        for (auto& m2 : mp2) {
            int digit = m2.first;
            int digit_bulls = m2.second.first;
            int digit_non_bull_guesses = m2.second.second;
            bulls += digit_bulls;
            int available_for_cows = mp3[digit] - digit_bulls;
            cows += min(available_for_cows, digit_non_bull_guesses);
        }

        string answer = to_string(bulls) + "A" + to_string(cows) + "B";
        return answer;
    }
};
