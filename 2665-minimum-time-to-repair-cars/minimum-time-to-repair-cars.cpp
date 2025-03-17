#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        auto ok = [&](long long mid) {
            long long repaired = 0;
            for (int r : ranks) {
                repaired += sqrt(mid / r);
                if (repaired >= cars) return true;
            }
            return repaired >= cars;
        };
        long long low = 1, high = 1e18, answer = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (ok(mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};
