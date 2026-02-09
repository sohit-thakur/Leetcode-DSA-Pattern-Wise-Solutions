class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        int sumCount = 0;
        int left = 0;
        for(int right=0;right<n;right++){
            sumCount += arr[right];
            while(sumCount>target&&left<=right){
                sumCount -= arr[left];
                left++;
            }
            if(sumCount==target){
                return {left+1,right+1};
            }
        }
        return {-1};
    }
};