class Solution {
public:
    int minimumLength(string s) {
        std::vector<int> freq(26, 0);
        for(char& c : s){
            freq[c - 'a']++;
        }
        int extra = 0;
        for(int i = 0; i < 26; ++i){
            if(freq[i] > 0) extra += (freq[i] == 1 ? 1 : (freq[i] % 2 == 1) ? 1 : 2);
        }
        return extra;
    }
};
