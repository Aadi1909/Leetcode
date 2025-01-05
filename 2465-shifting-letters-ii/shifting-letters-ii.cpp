class FenwickTree {
private:
    vector<int> tree;
    int size;
public:
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}
    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += index & -index;
        }
    }
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
    void range_update(int left, int right, int delta) {
        update(left, delta);
        update(right + 1, -delta);
    }
};
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        FenwickTree fenwick(n);
        for (const auto& shift : shifts) {
            int start = shift[0] + 1;
            int end = shift[1] + 1;
            int direction = shift[2];
            int delta = (direction == 1) ? 1 : -1;
            fenwick.range_update(start, end, delta);
        }
        string result = s;
        for (int i = 0; i < n; ++i) {
            int net_shift = fenwick.query(i + 1) % 26;
            if (net_shift < 0) net_shift += 26;
            result[i] = 'a' + (s[i] - 'a' + net_shift) % 26;
        }
        return result;
    }
};