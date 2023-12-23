class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        for(int i=1; i<gain.size(); i++){
            gain[i]+=gain[i-1];
        }
        int maxAlt=-1e9;
        for(int i=0; i<gain.size(); i++){
            maxAlt=max(maxAlt,gain[i]);
        }
        return max(0,maxAlt);
    }
};