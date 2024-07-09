class Solution {
public:
int maxProduct(vector<string>& words) {
		 vector<int> bit;
		 for(int i = 0; i < words.size(); ++i){
		  	int mask = 0;
		  	for(int j = 0; j < words[i].length(); ++j){
		  	 	int index = words[i][j] - 97;
		  	 	mask = (mask | (1LL << index));
		  	}
		  	bit.push_back(mask);
		 }
		 int answer = 0;
		 for(int i = 0; i < bit.size(); ++i){
		  	for(int j = i + 1; j < bit.size(); ++j){
		  	 	if((bit[i] & bit[j]) == 0){
		  	 	 	answer = max(answer, (int)words[i].size() * (int)words[j].size());
		  	 	}
		  	}
		 }
	return answer;
    }
};
