class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int suffixMin[] = new int [n];
        suffixMin[n-1] = arr[n-1];
        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = Math.min(suffixMin[i + 1],  arr[i]);
        }
        int answer = 1;
        int prefixMax = arr[0];
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > prefixMax) {
                prefixMax = arr[i];
            }
            if (prefixMax <= suffixMin[i + 1]) {
                answer += 1;
            }
        }
        return answer;
    }
}