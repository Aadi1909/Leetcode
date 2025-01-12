class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        std::vector<int> maxFreq(26, 0);
        for (const std::string& word : words2) {
            std::vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = std::max(maxFreq[i], freq[i]);
            }
        }

        std::vector<std::string> result;
        for (const std::string& word : words1) {
            std::vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }

            bool isSubset = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isSubset = false;
                    break;
                }
            }

            if (isSubset) {
                result.push_back(word);
            }
        }

        return result;
    }
};
