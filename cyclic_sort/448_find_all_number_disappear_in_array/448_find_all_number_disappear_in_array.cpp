class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int i=0;
        while(i<n){
            int correct = nums[i]-1;
            if(nums[i]!=nums[correct]){
                swap(nums[i],nums[correct]);
            }
            else{
                i++;
            }
        }
        i = 0;
        while(i<n){
            if(nums[i]!=i+1){
                ans.push_back(i+1);
            }
            i++;
        }
        return ans;
        
    }
};