class Solution {
public:
    int max_el(vector<int>& piles) {
        int ans = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            ans = max(ans,piles[i]);
        }
        return ans;
    }
    bool canEat(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + k - 1)/k;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = max_el(piles);
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (canEat(piles,h,mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};