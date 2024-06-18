class Solution {
public:
    vector<vector<string>>res;
    bool isPali(string&s){
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++,r--;
        }
        return true;
    }
    void solve(int l,string &s, vector<string>&st){
        if(l==s.length()){
            res.push_back(st);
            return;
        }
        string pa="";
        for(int i=l; i<s.length(); ++i){
            pa+=s[i];
            if(isPali(pa)){
                st.push_back(pa);
                solve(i+1,s,st);
                st.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> st;
        solve(0,s, st);
        return res;
    }
};