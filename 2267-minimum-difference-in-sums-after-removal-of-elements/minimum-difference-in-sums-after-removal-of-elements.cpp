class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;
        vector<long long> pre(n, 0), suf(n, 0);
        priority_queue<int> maxHeap;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            maxHeap.push(nums[i]);
            sum += nums[i];
            if (maxHeap.size() > k) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            pre[i] = sum;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            minHeap.push(nums[i]);
            sum += nums[i];
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            suf[i] = sum;
        }

        long long answer = LLONG_MAX;
        for (int i = k - 1; i < n - k; ++i) {
            answer = min(answer, pre[i] - suf[i + 1]);
        }

        return answer;
    }
};
