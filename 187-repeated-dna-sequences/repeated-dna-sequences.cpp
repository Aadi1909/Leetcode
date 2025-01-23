#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
#include <numeric>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::unordered_map<std::string, int> has;  // Use string as key
        std::deque<char> seq;
        std::vector<std::string> answer;
        for (int i = 0; i < (int)s.length(); ++i) {
            seq.push_back(s[i]);
            if (seq.size() > 10) {
                seq.pop_front();
            }
            if (seq.size() == 10) {
                std::string sequence = std::accumulate(seq.begin(), seq.end(), std::string(""));
                has[sequence]++;
                if (has[sequence] == 2) {
                    answer.push_back(sequence);
                }
            }
        }
        return answer;
    }
};
