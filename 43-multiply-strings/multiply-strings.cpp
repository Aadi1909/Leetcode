class Solution {
public:
    string multiply(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> BigInt(2 * (n + m),0);
        if((n==1 && s[0]=='0') ||(m==1 && t[0]=='0'))return "0";
        string answer;
        for (int i = m - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = n - 1; j >= 0; j--) {
                int mul = (s[j] - '0') * (t[i] - '0') + BigInt[i + j + 1] + carry;
                BigInt[i + j + 1] = mul % 10;
                carry = mul / 10;
            }
            BigInt[i] += carry;
        }                                         
        int i = 0;
        while (i < n + m && BigInt[i] == 0) {
            i++;
        }                   
        for (; i < n + m; i++) {
            answer += BigInt[i]+'0';
        } 
        return answer;
    }
};