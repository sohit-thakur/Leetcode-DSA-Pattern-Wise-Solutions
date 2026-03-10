class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double firstAvg = 0;
        double maxAvg = 0;
        double firstSum = 0;
        int l=0;
        for(int i=0;i<k;i++){
            firstSum += nums[i];
        }
        firstAvg = firstSum/k;
        maxAvg = firstAvg;
        for(int j=k;j<n;j++){
            firstSum += nums[j];
            firstSum -= nums[l];
            firstAvg = firstSum/k;
            maxAvg = max(maxAvg,firstAvg);
            l++;
        }
        return maxAvg;
    }
};