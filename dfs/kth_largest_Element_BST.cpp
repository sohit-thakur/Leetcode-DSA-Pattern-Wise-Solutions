class Solution {
public:
    void kthLargest(Node* root, vector<int>& ans){
        if(root == nullptr) return;
        ans.push_back(root->data);
        kthLargest(root->left, ans);   
        kthLargest(root->right, ans);   
    }

    int kthLargest(Node *root, int k) {
        vector<int> ans;
        kthLargest(root, ans);
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < ans.size(); i++){
            if(pq.size() < k){
                pq.push(ans[i]);
            } else if(ans[i] > pq.top()){
                pq.pop();
                pq.push(ans[i]);
            }
        }

        return pq.top();
    }
};
