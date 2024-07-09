class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < nums1.size(); ++i){
            int low = 0, hi = nums2.size()-1;
            bool ok = false;
            while(low <= hi) {
                int mid = (low + hi) / 2;
                if(nums1[i] == nums2[mid]){
                    ok = true;
                    break;
                } 
                else if(nums2[mid] < nums1[i]){
                    low = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            if(ok)st.insert(nums1[i]);
        }
        vector<int> answer;
        for(const auto &i : st){
            answer.push_back(i);
        }
        return answer;
    }
};