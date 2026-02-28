📌 Problem

Find the maximum depth (height) of a binary tree.

Maximum depth = number of nodes in the longest path from root to leaf.

🧠 Approach: DFS (Recursion) — Optimal

Idea:
For each node, depth =

1 + max(left subtree depth, right subtree depth)
⚙️ Algorithm Steps

If root == NULL → return 0

Recursively find left subtree depth

Recursively find right subtree depth

Return 1 + max(leftDepth, rightDepth)

💻 Code
class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base case: empty tree
        if(root == NULL)
            return 0;

        // Recursive case: calculate left and right depth
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Return maximum depth
        return 1 + max(leftDepth, rightDepth);
    }
};
🔎 Example

Tree:

        1
       / \
      2   3
     /
    4

Calculation:

maxDepth(4) = 1
maxDepth(2) = 2
maxDepth(3) = 1
maxDepth(1) = 3

Answer = 3

⏱️ Complexity

Time Complexity:

O(n)

Space Complexity:

O(h)

h = height of tree

🎯 Why DFS is Optimal

No extra data structures needed

Clean and short code

Interview preferred solution

📝 Git Commit Notes
Added optimal DFS recursive solution for Maximum Depth of Binary Tree.
Used postorder traversal to compute depth.
Time Complexity: O(n)
Space Complexity: O(h)