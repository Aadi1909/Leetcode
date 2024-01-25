class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>answer;
        set<int>a,b;
        for(int i=0; i<nums1.size(); i++){
            a.insert(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++){
            b.insert(nums2[i]);
        }
        set<int>tmp1,tmp2;
        for(int i=0; i<nums1.size(); i++){
            if(b.count(nums1[i])==0){
                tmp1.insert(nums1[i]);
            }
        }
        vector<int>v(tmp1.begin(),tmp1.end());
        answer.push_back(v);
        for(int i=0; i<nums2.size(); i++){
            if(a.count(nums2[i])==0){
                tmp2.insert(nums2[i]);
            }
        }
        vector<int>v2(tmp2.begin(),tmp2.end());
        answer.push_back(v2);
        return answer;
    }
};