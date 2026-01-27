class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int currSum = a[0];
        int maxSum = a[0];
       int tatkal = 0;
        
        for(int i=1;i<a.size();i++){
            tatkal = currSum+a[i];
            currSum = min(a[i],currSum+a[i]);
            maxSum = min(maxSum,currSum);
        }
        return maxSum;
    }
};
