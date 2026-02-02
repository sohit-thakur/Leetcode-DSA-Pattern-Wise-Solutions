/*
class Solution {
public:
    void dfs(TreeNode* root,vector<int> &ans){
        if(root==nullptr) return;
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
        
    }
};
*/

class Solution{
public:
  vector<int> inorderTraversal(TreeNode* root){
    vector<int> ans;
    if(root==nullptr) return ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while(curr!=nullptr||!st.empty()){
        while(curr!=nullptr){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        ans.push_back(curr->val);
        st.pop();

        curr = curr->right;

    }
    return ans;
  }
};