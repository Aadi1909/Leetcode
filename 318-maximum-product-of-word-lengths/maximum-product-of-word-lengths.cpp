class Solution {
public:
int maxProduct(vector<string>& words) {
    vector<string> a;
    for(int i = 0; i < words.size(); ++i) {
        string s(26, '0');
        for(int j = 0; j < words[i].size(); ++j) {
            int index = words[i][j] - 'a';
            s[index] = '1';
        }
        a.push_back(s);
    }

    int answer = 0;
    for(int i = 0; i < a.size(); ++i) {
        for(int j = i + 1; j < a.size(); ++j) {
            bool ok = true;
            for(int k = 0; k < 26; ++k) {
                if(a[i][k] == '1' && a[j][k] == '1') {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                answer = max(answer, (int)words[i].length() * (int)words[j].length());
            }
        }
    }
    return answer;
    }
}; 