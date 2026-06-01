class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int n = nums.size();
        // int max_product = INT_MIN;
        // for (int i = 0; i < n; i++) {
        //     int pro = 1;
        //     for (int j = i; j < n; j++) {
        //         pro *= nums[j];
        //         max_product = max(max_product,pro);
        //     }
        // }
        // return max_product;
        // time complexity - n^2
        int n = nums.size();
        int ans = INT_MIN;
        int prefix = 1, sufix = 1;
        for (int i = 0; i < n; i++) {
            if (prefix == 0) {
                prefix = 1;
            }
            if (sufix == 0) {
                sufix = 1;
            }
            prefix *= nums[i];
            sufix *= nums[n-i-1];
            ans = max(ans,max(prefix,sufix));
        }
        return ans;
    }
};