class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        char digit = '0';
        for(char c : s){
            digit = max(digit, c);
        }
        string cc = s;
        sort(cc.begin(), cc.end());
        if(s[0] != digit){
            for(int i = s.length() - 1; i > 0; --i){
                if(s[i] == digit){
                    swap(s[i], s[0]);
                    break;
                }
            }
            return stoi(s);
        }
        int n = s.length();
        for(int i = 0; i < n; ++i){
            if(s[i] < cc[n - i - 1]){
                int idx = s.find_last_of(cc[n - i - 1]);
                swap(s[i], s[idx]);
                break;
            }
            else continue;
        }
        return stoi(s);
    }
};