class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0){
            return true;
        }
        int sz = flowerbed.size();
        for(int i = 0; i < sz; i++){
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == sz-1 || flowerbed[i+1] == 0)){
                i++;
                n--;
            }
            if(!n) return true;
        }
        return false;
    }
};