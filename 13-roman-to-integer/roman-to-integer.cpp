class Solution {
public:
    int romanToInt(string s) {
        
        int answer = 0;

        unordered_map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        for(int i = 0; i < s.length(); i++){
            if(mp[s[i]] < mp[s[i+1]]){
                answer -= mp[s[i]];
            }
            else{
                answer += mp[s[i]];
            }
        } 
        
        /*
        for(int i = s.length() - 1; i > -1; i--){
            if(s[i] == 'V'){
                answer += 5;
                if(i > 2 && s[i - 1] == 'I' && s[i-2] == 'I' && s[i-3] == 'I'){
                    answer -= 3;
                    i -= 3;
                }
                else if(i > 1 && s[i-1] == 'I'  && s[i-2] == 'I'){
                    answer -= 2;
                    i -= 2;
                }
                else if(i > 0 && s[i-1] == 'I'){
                    answer -= 1;
                    i -= 1;
                }
            } 
            else if(s[i] == 'X'){
                answer += 10;
                if(i > 0 && s[i-1] == 'I'){
                    answer -= 1;
                    i -= 1;
                }
            }
            else if(s[i] == 'L'){
                answer += 50;
                if(i > 0 && s[i-1] == 'X'){
                    answer -= 10;
                    i -= 1;
                }
            }
            else if(s[i] == 'C'){
                answer += 100;
                if(i > 0 && s[i-1] == 'X'){
                    answer -= 10;
                    i -= 1;
                }
            }
            else if(s[i] == 'D'){
                answer += 500;
                if(i > 0 && s[i-1] == 'C'){
                   answer -= 100;
                    i -= 1;
                }
            }
            else if(s[i] == 'M'){
                answer += 1000;
                if(i > 0 && s[i-1] == 'C'){
                    answer -= 100;
                    i -= 1;
                }
            }
            else{
                answer += 1;
            }
        }
        */
        return answer;
    }
};