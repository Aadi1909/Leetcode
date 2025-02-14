class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;
        for(int num : nums){
            pq.push(num);
        }
        int op = 0;
        while (pq.size() > 1 && !(pq.top() >= k)){
            int64_t x = pq.top(); pq.pop();
            // if(x >= k) break;
            int64_t y = pq.top(); pq.pop();
            int64_t val = x * 2LL + y;
            pq.push(val);
            op++;
        }
        return op;
    }
};