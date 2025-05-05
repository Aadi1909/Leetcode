class Solution {
public:
    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int rotationsTop = 0, rotationsBottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != x && bottoms[i] != x) {
                return -1;
            } else if (tops[i] != x) {
                rotationsTop++;
            } else if (bottoms[i] != x) {
                rotationsBottom++;
            }
        }
        return min(rotationsTop, rotationsBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1 || tops[0] == bottoms[0]) return result;
        return check(bottoms[0], tops, bottoms);
    }
};
