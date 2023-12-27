class Solution {
public:
    int maxProfit(vector<int>& price) {
        int profit=0,least=price[0];
        int n=price.size();
        if(n==1){
            return 0;
        }
        bool ok=false;
        for(int i=1; i<n; i++){
            if(price[i]<price[i-1]){
                profit+=price[i-1]-least;
                least=price[i];
            }
            if(price[i]<least){
                least=price[i];
            }
        }
        if(price[n-1]>=price[n-2]){
            profit+=price[n-1]-least;
        }
        return profit;
    }
};