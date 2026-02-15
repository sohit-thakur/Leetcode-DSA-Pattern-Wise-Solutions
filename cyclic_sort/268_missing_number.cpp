class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i] < n && nums[i] != nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
            }
            else{
            i++;
            }
        }
        i=0;
        while(i<n){
            if(nums[i]!=i){
                return i;
            }
            i++;
        }
        return n;
    }
};