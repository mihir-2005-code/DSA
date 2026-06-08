class Solution {
public:
    int fun(vector<int>& nums, int pages) {
        int students = 1;
        int pages_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pages_count + nums[i] <= pages) {
                pages_count += nums[i];
            }
            else {
                students++;
                pages_count = nums[i];
            }
        }
        return students;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (fun(nums,mid) > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};