class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int mxDiv=2, len=(int)str1.length(), len2=str2.length();
        int f[26] = {}, s[26] = {};
        int ll = min(len, len2);
        for(int i=0; i<ll; i++){
            if(str1[i]!=str2[i])return "";
        }
        for(int i = 0; i < len; i++){
            f[str1[i]-'A']++;
        }
        for(int j = 0; j < len2; j++){
            s[str2[j]-'A']++;
        }
        for(int i = 0; i < 26; i++){
            if(f[i] == 0 && s[i] > 0 || f[i] > 0 && s[i] == 0) return "";
        }
        for(int i=2; i<=len; i++){
            if(len%i==0 && len2%i==0)mxDiv = i;
        }
        if(str1 == str2){
            return str1;
        }
        if(len2 <= 1){
            return str2;
        }
        if(len <= 1) return str1;
        bool ok=false;
        int times=len/mxDiv;
        string tmp="";
        while(times--){
            tmp+=str1.substr(0,mxDiv);
        }
        if(tmp==str1)ok=true;
        for(int i=0; i<str1.length(); i++){
            if(str1[i]==str2[0]){
                int cnt=0;
                int k=0;
                for(int j=i; j<mxDiv; j++){
                    if(str1[j]==str2[k]){
                        k++;
                        cnt++;
                    }
                }
                if(cnt==mxDiv && ok){
                    return str1.substr(0, mxDiv);
                }
            }
        }
        return "";
    }
};