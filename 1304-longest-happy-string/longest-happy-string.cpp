class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            int count = p.first;
            char ch = p.second;
            if(ans.length() >= 2 && ans[ans.length() - 1] == p.second && 
            ans[ans.length() - 2] == p.second){
                if(pq.empty()) break;
                auto tmp = pq.top();
                pq.pop();
                ans += tmp.second;
                if(tmp.first - 1 > 0) {
                    pq.push({tmp.first - 1, tmp.second});
                }
            }
            else{
                count--;
                ans += ch;
            }
            if(count > 0){
                pq.push({count, ch});
            }
        }
        return ans;
    }
};