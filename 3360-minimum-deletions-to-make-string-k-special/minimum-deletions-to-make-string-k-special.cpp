class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<int,int>mp;
        int deleted=0,ans=word.size();
        for(int i=0; i<word.length(); i++){
            mp[word[i]]++;
        }
        vector<int>freq;
        for(auto m:mp){
            freq.push_back(m.second);
        }
        sort(freq.begin(),freq.end());
        for(int i = 0; i < freq.size(); ++i){     
        int res = deleted, minFreq = freq[i];    
            for(int j = freq.size()-1; j > i; --j){ 
                if(freq[j] - minFreq <= k) break; 
                res += freq[j] - minFreq - k;        
            }
            ans = min(ans, res);                     
            deleted += freq[i];
        }
    return ans;
    }
};