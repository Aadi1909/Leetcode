class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long  n=piles.size();
        long long low=1,hi=1e9,ans=0;
        while(low<=hi){
            long long mid=low+(hi-low)/2;
            bool time=eatKoko(piles,mid,h);
            if(time){
                ans=mid;
                hi=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool eatKoko(vector<int>piles, long long mid, long long h){
        long long timeTaken=0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]%mid!=0){
                timeTaken+=(piles[i]/mid)+1;
            }
            else{
                timeTaken+=(piles[i]/mid);
            }
        }
        if(timeTaken<=h){
            return true;
        }
        else{
            return false;
        }
    }
};