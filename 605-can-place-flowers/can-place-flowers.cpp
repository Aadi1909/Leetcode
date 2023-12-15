class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int oddplace = 0, evenplace = 0;
        int size = flowerbed.size();
        if(size == 1 && flowerbed[0] == 0 && n <= 1) return true;
        for(int i = 1; i < size; i+=2){
            if(i == size-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0) oddplace++;
            else if(i < size && flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)  oddplace++;
        }
        for(int i = 0; i < size; i+=2){
            if(i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                evenplace++;
            }
            else if(i == size - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0) evenplace++;
            else if(i > 0 && flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                evenplace++;
            }
        }

        return oddplace >= n || evenplace >= n;
    }
};