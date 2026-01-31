/*class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ans;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
        
    }
};*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];

        while(low < high){
            int mid = low + (high - low) / 2;
            int count = 0;
            int i = n - 1, j = 0;

            while(i >= 0 && j < n){
                if(matrix[i][j] <= mid){
                    count += i + 1;
                    j++;
                } else {
                    i--;
                }
            }

            if(count >= k) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};

