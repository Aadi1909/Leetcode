class Solution {
public:
    string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts) {
        // can use difference array
        int n = s.length();
        std::vector<int> diff(n + 1, 0);
        for(int i = 0; i < shifts.size(); ++i){
            int l = shifts[i][0];
            int r = shifts[i][1];
            if(shifts[i][2]){
                diff[l]++;
                diff[r + 1]--;
            }
            else{
                diff[l]--;
                diff[r + 1]++;
            }
        }
        for(int i = 1; i < n; ++i){
            diff[i] += diff[i - 1];
        }
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