
//****kadane's only work for the sum of the subarray of different size variable


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curr = 1;
        int total = INT_MIN;

        for (int i = 0; i < n; i++) {
            curr *= nums[i];
            total = max(total, max(curr, nums[i]));
            if (curr == 0) curr = 1;
        }

        int curr1 = 1;


        for (int i = n -1; i >= 0; i--) {
            curr1 *= nums[i];
            total = max(total, max(curr1, nums[i]));
            if (curr1 == 0) curr1 = 1;
        }

        return total;  
    }
};
