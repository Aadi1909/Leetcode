class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1e4);
        for(int i = 0; i < arr1.size(); ++i){
          cnt[arr1[i]]++;
        }
        vector<int> answer;
        for(int i = 0; i < arr2.size(); ++i){
          while(cnt[arr2[i]]--){
            answer.push_back(arr2[i]);
          }
        }
        set<int> st;
        vector<int> temporary;
        for(int i = 0; i < arr2.size(); ++i) st.insert(arr2[i]);
        for(int i = 0; i < arr1.size(); ++i) {
          if(st.find(arr1[i]) == st.end()){
            temporary.push_back(arr1[i]);
          }
        }
        sort(temporary.begin(), temporary.end());
        for(int& t : temporary){
          answer.push_back(t);
        }
        return answer;

    }
};