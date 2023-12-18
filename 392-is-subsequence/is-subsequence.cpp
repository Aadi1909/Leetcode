class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool ok=false;
        for(int i=0; i<t.length(); i++){
            if(t[i]==s[0]){
                s.erase(0,1);
            }
        }
        return s.size()==0;
    }
};