class Solution {
private:
    vector<int> curr;
    vector<vector<int>> res;
    void  backtrack(int n,int k,int start,vector<int> &curr,vector<vector<int>> &res){
        if(curr.size()==k){
            res.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            backtrack(n,k,i+1,curr,res);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n,k,1,curr,res);
        return res;
    }
};