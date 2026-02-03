class Solution {
  public:
    void bfs(Node* root, vector<int>& ans) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (i == 0) {
                    ans.push_back(curr->data);
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }

    vector<int> leftView(Node* root) {
        vector<int> ans;
        bfs(root, ans);
        return ans;
    }
};
