
class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) {
            return 0;
        }

        long long res = 0;
        bool neg = false;
        bool ok = false;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (ok) {
                    break; 
                }
                continue;
            }

            if (res > INT_MAX) {
                return INT_MAX;
            }

            if (res < INT_MIN) {
                return INT_MIN;
            }

            if (s[i] == '-') {
                if (ok) {
                    break; 
                }
                neg = true;
                ok = true;
            } else if (s[i] == '+') {
                if (ok) {
                    break; 
                }
                ok = true;
            } else if (!(s[i] >= '0' && s[i] <= '9')) {
                break; 
            } else {
                ok = true;
                res = res * 10 + s[i] - '0';

                if (res > INT_MAX) {
                    return neg ? INT_MIN : INT_MAX;
                }
            }
        }

        return neg ? -res : res;
    }
};
