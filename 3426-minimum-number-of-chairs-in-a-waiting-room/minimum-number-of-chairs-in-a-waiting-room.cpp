class Solution {
public:
    int minimumChairs(string s) {
        int currentChairs = 0;
        int needed = 0;
        for (char& c : s) {
            if (c == 'E') {
                if (!currentChairs) needed += 1;
                else currentChairs -= 1;
            } else {
                currentChairs += 1;
            }
        }
        return needed;
    }
};