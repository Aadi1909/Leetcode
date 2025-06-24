class Solution {
    public int trap(int[] height) {
       Stack<Integer> left = new Stack<>();
       Stack<Integer> right = new Stack<>();
       int n = height.length;
       int l[] = new int[n];
       int r[] = new int[n];
       Arrays.fill(l, -1);
       Arrays.fill(r, -1); 
       right.push(height[n - 1]);
       for (int i = n - 2; i >= 0; --i) {
        while (!right.empty() && height[i] >= right.peek()) {
            right.pop();
        }
        if (right.empty()) right.push(height[i]);
        r[i] = right.peek();
       }
       left.push(height[0]);
       for (int i = 1; i < n; ++i) {
        while (!left.empty() && left.peek() <= height[i]) {
            left.pop();
        }
        if (left.empty()) left.push(height[i]);
        l[i] = left.peek();
       }

       int answer = 0;
       for (int i = 1; i + 1 < n; ++i) {
        answer += Math.min(l[i], r[i]) - height[i];
       }
       return answer;
    }
}