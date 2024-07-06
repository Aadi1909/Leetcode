class Solution {
    public int passThePillow(int n, int time) {
        int x = time / (n-1);
        return x % 2 == 0 ? (time % (n-1) + 1) : (n - time % (n - 1));

    }
}