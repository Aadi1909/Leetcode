class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
      int answer = 0;
      queue<pair<int, int>> q;
      for(int i = 0; i < tickets.size(); ++i){
        q.push({tickets[i], i});
      }
      while(!q.empty()){
        auto [x, y] = q.front();
        if(y == k && x == 1){
          break;
        }
        q.pop();
        if(x > 0){
          x--;
          answer++;
          q.push({x, y});
        }
      }
      return answer + 1;
    }
};