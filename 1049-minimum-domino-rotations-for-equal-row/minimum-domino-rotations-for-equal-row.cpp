class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // first create the map to count if it's possible or not to make all equal
        map<int, int> dominoValues, topTrack, bottomTrack;
        map<int, set<int>> counting;
        for (int i = 0; i < tops.size(); ++i) {
            dominoValues[tops[i]]++;
            topTrack[tops[i]]++;
            counting[tops[i]].insert(i);
        }
        for (int j = 0; j < bottoms.size(); ++j) {
            dominoValues[bottoms[j]]++;
            bottomTrack[bottoms[j]]++;
            counting[bottoms[j]].insert(j);
        }
        vector<pair<int, int>> pairs(dominoValues.begin(), dominoValues.end());
        sort(pairs.begin(), pairs.end(), [](auto& x, auto& y){
                if (x.second < y.second) return true;
                return false;
        });
        int len = pairs.size();
        int topMin = 1e9, bottomMin = 1e9;
        int sz = tops.size();
        for (int i = len - 1; i >= 0 && counting[pairs[i].first].size() == sz; --i) {
            int topVal = topTrack[pairs[i].first];
            int bottomVal = bottomTrack[pairs[i].first];
            topMin = min(topMin, abs(topVal - (int)tops.size()));
            bottomMin = min(bottomMin, abs(bottomVal - (int)bottoms.size()));
        }
        int answer = min(topMin, bottomMin);
        return answer == 1e9 ? -1 : answer;
    }
};