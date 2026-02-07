class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;

        vector<int> result(nums.size());

        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                result[k] = nums[i] * nums[i];
                i++;
            } else {
                result[k] = nums[j] * nums[j];
                j--;
            }
            k--;
        }

        return result;
    }
};
