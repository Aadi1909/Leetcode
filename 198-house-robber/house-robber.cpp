class Solution {
public:
    int rob(vector<int>& a) {
        int f=a[0],s=0;
        for(int i=1; i<a.size(); i++){
            int tmp=s;
            s=max(f,s);
            f=a[i]+tmp;
        }
        return max(f,s);
    }
};