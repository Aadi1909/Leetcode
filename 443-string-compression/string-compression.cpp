class Solution {
public:
    int compress(vector<char>& ch) {
        string s="";
        if(ch.size()==1){
            return 1;
        }
        //counting the frequency of chars
        int cnt=0;
        char c;
        for(int i=0; i<ch.size(); i++){
            if(i==0){
                c=ch[i];
                cnt++;
                continue;
            }
            if(ch[i]==c){
                cnt++;
            }
            else{
                s+=c;
                if(cnt>1)s+=to_string(cnt);
                cnt=1;
                c=ch[i];
            }
        }
        s+=c;
        if(cnt>1)s+=to_string(cnt);
        //reasigning to char array
        for(int i=0; i<s.length(); i++){
            ch[i]=s[i];
        }
        return s.length();
    }
};