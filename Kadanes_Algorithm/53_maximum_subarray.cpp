class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCount = nums[0];
        int currCount = nums[0];
        int tatkal = 0;
        for(int i=1;i<nums.size();i++){
            tatkal = currCount+nums[i];
            currCount = max(tatkal,nums[i]);
            maxCount = max(maxCount,currCount);
        }
        return maxCount;
        
    }
};
