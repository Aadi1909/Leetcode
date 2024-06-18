class Solution {
public:
    vector<vector<string>>res;
    void solve(int low,vector<string>&str,string&s, set<string>st){
        if(low==s.length()){
            res.push_back(str);
            return;
        }
        string t="";
        for(int i=low; i<s.length(); ++i){
            t+=s[i];
            if(st.count(t)){
                str.push_back(t);
                solve(i+1,str,s,st);
                str.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(int i=0; i<wordDict.size(); ++i){
            st.insert(wordDict[i]);
        }
        vector<string> ans;
        vector<string> str;
        solve(0,str,s,st);
        for(int j=0; j<res.size(); ++j){
            string st="";
            for(int i=0; i+1<res[j].size(); ++i){
                st+=res[j][i]+" ";
            }
            st+=res[j].back();
            ans.push_back(st);
        }
        return ans;
    }
};