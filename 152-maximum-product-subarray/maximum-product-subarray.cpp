class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_product = INT_MIN;
        for (int i = 0; i < n; i++) {
            int pro = 1;
            for (int j = i; j < n; j++) {
                pro *= nums[j];
                max_product = max(max_product,pro);
            }
        }
        return max_product;
    }
};