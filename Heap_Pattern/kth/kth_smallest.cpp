class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> maxheap;
        for(int i=0;i<k;i++){
            maxheap.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(arr[i]<maxheap.top()){
                maxheap.pop();
                maxheap.push(arr[i]);
            }
        }
        return maxheap.top();
    }
};