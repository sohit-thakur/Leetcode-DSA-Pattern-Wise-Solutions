//Both using Recursion and Stack;
 /*
class Solution {
public:
    void dfs(TreeNode* root,vector<int>& ans){
        if(root==nullptr) return;
        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
        
    }
};
*/

class Solution{
public:
  vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;
    if(root==nullptr) return ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        ans.push_back(node->val);
        st.pop();
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return ans;
  }
};
