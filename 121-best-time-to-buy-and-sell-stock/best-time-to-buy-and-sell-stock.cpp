class Solution {
public:
    int maxProfit(vector<int>& a) {
        int profit=0,least=a[0];
        int n=a.size();
	    for(int i=1; i<n; i++){
		    profit=max(profit,a[i]-least);
		    least=min(least,a[i]);
	    }
	    return profit;
    }
};