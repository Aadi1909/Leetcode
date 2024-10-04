class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        long long answer = 0;
        sort(skills.begin(), skills.end());
        int lo = 0, hi = skills.size() - 1;
        int last = skills[lo] + skills[hi];
        while(lo < hi){
            if(skills[lo] + skills[hi] != last){
                return -1;
            }
            answer += (skills[lo] * skills[hi]);
            lo++, hi--;
        }
        return answer;
    }
};