class Solution {
public:
    // Check if we can make m bouquets on given 'day'
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int consecutive = 0;  // adjacent bloomed flowers count

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                consecutive++;           // flower bloomed ✅
                if (consecutive == k) {  // completed one bouquet
                    bouquets++;
                    consecutive = 0;     // reset for next bouquet
                }
            } else {
                consecutive = 0;         // chain broken ❌
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // Edge case: impossible
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                high = mid - 1;  // try earlier day
            } else {
                low = mid + 1;   // need more days
            }
        }
        return low;
    }
};