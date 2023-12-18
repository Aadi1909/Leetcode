class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int low = 0, hi = 1;
        while (hi < (int) a.size()) {
            if (a[low] == 0 && a[hi] != 0) {
                swap(a[low], a[hi]);
                low++, hi++;
            } else if (a[low] != 0 && a[hi] == 0) {
                low++, hi++;
            } else if (a[low] == 0 && a[hi] == 0) {
                hi++;
            }
            else{
                low++, hi++;
            }
        }
    }
};