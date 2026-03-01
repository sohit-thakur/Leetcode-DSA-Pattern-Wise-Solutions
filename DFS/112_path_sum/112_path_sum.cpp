class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right){
            return targetSum == root->val;
        }
        int rem = targetSum - root->val;
        bool leftCheck = hasPathSum(root->left,rem);
        bool rightCheck = hasPathSum(root->right,rem);
        return leftCheck || rightCheck;
    }
};