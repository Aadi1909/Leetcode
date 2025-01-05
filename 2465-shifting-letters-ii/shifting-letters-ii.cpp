class Solution {
public:
    string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts) {
        // can use difference array
        int n = s.length();
        std::vector<int> diff(n + 1, 0);
        for(int i = 0; i < shifts.size(); ++i){
            int l = shifts[i][0];
            int r = shifts[i][1];
            diff[l] += (shifts[i][2] ? 1 : -1);
            diff[r + 1] += (shifts[i][2] ? -1 : 1);
        }
        partial_sum(diff.begin(), diff.end(), diff.begin());
        int k = 26;
        for(int i = 0; i < n; ++i){
            int pos = s[i] - 'a';
            pos += diff[i];
            pos = (((pos % k) + k) % k);
            s[i] = static_cast<char>(pos + 97);
        }   
        return s;
    }
};