class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      sort(deck.begin(), deck.end());
      queue<int> q;
      for(int i = deck.size() - 1; i >= 0; i--){
        if(!q.empty()){
          q.push(q.front());
          q.pop();
        }
        q.push(deck[i]);
      }
      vector<int> answer(deck.size());
      for(int i = deck.size() - 1; i >= 0; --i){
        answer[i] = q.front();
        q.pop();
      }
      return answer;
    }
};