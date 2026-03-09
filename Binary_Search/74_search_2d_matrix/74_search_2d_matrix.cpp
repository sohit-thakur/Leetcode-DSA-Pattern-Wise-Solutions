class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int n = matrix.size();
        int m = matrix[0].size();
        while(i<n){
            if(matrix[i][m-1]>=target){
                int low = 0;
                int high = m-1;
                while(low<=high){
                    int mid = low + (high-low)/2;
                    if(matrix[i][mid]==target){
                        return true;
                    }
                    else if(matrix[i][mid]>target){
                        high = mid-1;
                    }
                    else{
                        low = mid+1;
                    }
                }
            }
            i++;
        }
        return false;
    }
};