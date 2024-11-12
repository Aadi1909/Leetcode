class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int size = items.size();
        vector<int> prefMax(size);
        sort(items.begin(), items.end(), [](auto& l, auto& r){
            return l[0] < r[0];            
        });
        for(int i = 1; i < size; ++i) {
            items[i][1] = max(items[i - 1][1], items[i][1]);
        }
        vector<int> answer;
        for(int i = 0; i < queries.size(); ++i) {
            int lo = 0, hi = size - 1;
            int maxx = 0;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (items[mid][0] <= queries[i]) {
                    maxx = max(maxx, items[mid][1]);
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
