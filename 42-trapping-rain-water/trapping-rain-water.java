class Solution {
    public int trap(int[] height) {
       Stack<Integer> left = new Stack<>();
       Stack<Integer> right = new Stack<>();
       int n = height.length;
       int l[] = new int[n];
       int r[] = new int[n]; 
       right.push(height[n - 1]);
       r[n - 1] = -1;
       for (int i = n - 2; i >= 0; --i) {
        while (!right.empty() && height[i] >= right.peek()) {
            right.pop();
        }
        if (right.empty()) right.push(height[i]);
        if (!right.empty()) {
            r[i] = right.peek();
        } else {
            r[i] = -1;
        }
       }
       left.push(height[0]);
       l[0] = -1;
       for (int i = 1; i < n; ++i) {
        while (!left.empty() && left.peek() <= height[i]) {
            left.pop();
        }
        if (left.empty()) left.push(height[i]);
        if (!left.empty()) {
            l[i] = left.peek();
        } else {
            l[i] = -1;
        }
       }

       int answer = 0;
       int index =  1;
       while(index < n - 1) {
        answer += Math.min(l[index], r[index]) - height[index];
        index++;
       }
       return answer;
    }
}