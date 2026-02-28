📌 Problem: Minimum Depth of Binary Tree

Definition:
Minimum depth = number of nodes from root to nearest leaf node.

Leaf node condition:

node->left == NULL && node->right == NULL
🧠 Approach: BFS (Level Order Traversal)

Idea:

Traverse tree level by level

First leaf node encountered → return depth

BFS guarantees shortest path

⚙️ Algorithm Steps

If root == NULL → return 0

Create queue and push root

Initialize depth = 1

While queue not empty:

Get current level size

Traverse all nodes in level

If leaf found → return depth

Push left and right children

Increase depth after each level

💻 Code
class Solution {
public:
    int minDepth(TreeNode* root) {
        // Step 1: Base case
        if(root == NULL)
            return 0;

        // Step 2: Create queue for BFS
        queue<TreeNode*> q;
        q.push(root);

        // Step 3: Initialize depth
        int depth = 1;

        // Step 4: BFS traversal
        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Step 5: Check leaf node
                if(node->left == NULL && node->right == NULL)
                    return depth;

                // Step 6: Push children
                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            // Step 7: Increase depth
            depth++;
        }

        return depth;
    }
};
⏱️ Complexity

Time Complexity:

O(n)

Space Complexity:

O(n)
🎯 Why BFS is Best
BFS	DFS
Finds minimum depth faster ✅	May explore full tree ❌
Stops early ✅	Slower ❌
Best for shortest path problems ✅	Not optimal ❌
🧩 Interview Pattern Recognition

Use BFS when question says:

Minimum depth

Shortest distance

Nearest node

Level traversal

📝 Git Commit Message Example
Added BFS solution for Minimum Depth of Binary Tree.
Used level order traversal to find first leaf node.
Time Complexity: O(n), Space Complexity: O(n).