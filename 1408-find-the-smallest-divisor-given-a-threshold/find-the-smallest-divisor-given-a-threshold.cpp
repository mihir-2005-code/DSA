class Solution {
public:
    bool is_smallest(vector<int>& nums,int k, int threshold) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + k - 1)/k;
        }
        return sum <= threshold;
    }
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = findMax(nums);
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (is_smallest(nums,mid,threshold)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};