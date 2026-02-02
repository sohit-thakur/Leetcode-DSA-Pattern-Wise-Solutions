class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        int sum = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            sum += q.front()->data;
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return sum;
    }
};