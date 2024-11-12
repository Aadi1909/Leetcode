class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int size = items.size();
        vector<int> prefMax(size);
        vector<pair<int, int>> a(size);
        for(int i = 0; i < size; ++i) {
            a[i].first = items[i][0];
            a[i].second = items[i][1];
        }
        sort(a.begin(), a.end());
        prefMax[0] = a[0].second;
        for(int i = 1; i < size; ++i) {
            prefMax[i] = max(prefMax[i - 1], a[i].second);
        }
        vector<int> answer;
        for(int i = 0; i < queries.size(); ++i) {
            int lo = 0, hi = size - 1;
            int maxx = 0;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (a[mid].first <= queries[i]) {
                    maxx = max(maxx, prefMax[mid]);
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            answer.push_back(maxx);
        }
        
        return answer;
    }
};
