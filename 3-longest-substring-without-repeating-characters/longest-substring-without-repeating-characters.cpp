class Solution {
public:
    int lengthOfLongestSubstring(string a) {
          std::set<int> st;
          int count = 0, maxE = 0;
          int low = 0;
          for(int i = 0; i < a.length(); ++i){
             if(st.count(a[i]) == 0){
                st.insert(a[i]);
                count++;
             }
             else{
                 maxE = std::max(maxE, count);
                 while(low < a.length()){
                     if(a[low] == a[i]){
                         ++low;
                         break;
                     }
                     st.erase(a[low]);
                     ++low, --count;
                 }
               }
             maxE = std::max(maxE, count);
          }
        return maxE;
    }
};