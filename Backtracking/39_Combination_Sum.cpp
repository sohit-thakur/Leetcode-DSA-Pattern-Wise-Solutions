#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& candidates, int target, vector<int>& curr, int start, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], curr, i, res);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        //sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, curr, 0, res);
        return res;
    }
};
