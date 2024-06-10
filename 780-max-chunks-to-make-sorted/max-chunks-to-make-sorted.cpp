class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int answer = 0;
        int sum = 0, low = 0;
        bool ok = false;
        while(low < arr.size()){
            if(arr[low] == 0){
                ok = true;
                int dist = low * (low + 1) / 2;
                if(sum == dist){
                    answer++;
                }   
            }
			if(ok == false){
                sum += arr[low];
            }
            else if(arr[low] != 0 ){
                if(sum + arr[low] == low * (low + 1)/ 2){
                    answer++;
                }
				sum += arr[low];
            }
            low++;
        }
        return answer;
    }
};