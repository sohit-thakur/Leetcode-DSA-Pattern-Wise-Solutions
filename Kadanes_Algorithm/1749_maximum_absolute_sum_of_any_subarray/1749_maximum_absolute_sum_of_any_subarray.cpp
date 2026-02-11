class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int totalMax = nums[0];
        int totalMin = nums[0];
        for(int i=1;i<n;i++){
            currMax = max(nums[i],currMax+nums[i]);
            currMin = min(nums[i],currMin+nums[i]);

            totalMax = max(currMax,totalMax);
            totalMin = min(currMin,totalMin);
        }
        return max(totalMax,abs(totalMin));
    }
};