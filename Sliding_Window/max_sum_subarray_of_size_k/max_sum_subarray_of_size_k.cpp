class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int firstCount = 0;
        for(int i=0;i<k;i++){
            firstCount += arr[i];
        }
        int maxCount = firstCount;
        for(int i=k;i<n;i++){
            firstCount = firstCount + arr[i];
            firstCount -= arr[i-k];
            maxCount = max(maxCount,firstCount);
        }
        return maxCount;
    }
};
