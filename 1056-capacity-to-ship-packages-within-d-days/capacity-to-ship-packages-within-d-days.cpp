class Solution {
public:
    int min_Days(vector<int>& weights,int k) {
        int days_need = 0;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > k) {
                days_need ++;
                sum = weights[i];
            }
        }
        return days_need + 1;
    }
    int findMax(vector<int>& weights) {
        int maxi = 0;
        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi,weights[i]);
        }
        return maxi;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = findMax(weights);
        int right = accumulate(weights.begin(), weights.end(), 0);;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (min_Days(weights,mid) <= days) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};