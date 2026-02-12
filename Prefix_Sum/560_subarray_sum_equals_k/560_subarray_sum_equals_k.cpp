class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int count = 0;
        freq[0] = 1;
        int prefixSum = 0;
        for(int i=0;i<nums.size();i++){
            prefixSum = prefixSum + nums[i];
            if(freq.find(prefixSum-k)!=freq.end()){
                count = count + freq[prefixSum-k];
            }
            freq[prefixSum]++;
        }
        return count;
    }
};