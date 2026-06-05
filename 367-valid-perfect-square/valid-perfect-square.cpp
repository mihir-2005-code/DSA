class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while (low <= high) {
            long long mid = low + (high - low)/2;
            if (mid*1LL*mid == num) {
                return true;
            }
            else if (mid*1LL*mid < num) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};