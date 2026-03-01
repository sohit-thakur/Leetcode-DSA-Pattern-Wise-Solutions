📌 Problem: Path Sum (LeetCode 112)

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values equals targetSum.

Path must start from root

Path must end at a leaf node

Leaf = node with no left and right child

🧠 Approach: Recursion (DFS)
Core idea

At each node:

Subtract current node value from targetSum

Pass remaining sum (rem) to children

If you reach a leaf node, check if remaining sum equals node value

🔁 Dry Run Example

Tree:

      5
     / \
    4   8
   /
  11

targetSum = 20

Steps:

20 - 5 = 15
15 - 4 = 11
11 - 11 = 0 → leaf → return true
💻 Code Explanation
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // Base case: if tree is empty
        if(!root) return false;
        
        // If leaf node, check sum
        if(!root->left && !root->right){
            return targetSum == root->val;
        }
        
        // Remaining sum after subtracting current node
        int rem = targetSum - root->val;
        
        // Check left and right subtree
        bool leftCheck = hasPathSum(root->left, rem);
        bool rightCheck = hasPathSum(root->right, rem);
        
        // Return true if any path matches
        return leftCheck || rightCheck;
    }
};
🌳 Recursive Tree Flow
hasPathSum(root, target)

            root
         target-root->val
          /           \
   check left     check right
⏱️ Complexity Analysis
Time Complexity
O(N)

Visit each node once

Space Complexity
O(H)

H = height of tree

recursion stack

Worst case:

O(N) → skewed tree
O(log N) → balanced tree
✅ Why this works

Because every recursive call:

reduces the problem size

checks valid root-to-leaf path only

🧾 Interview Key Points

✔ DFS problem
✔ Root-to-leaf condition important
✔ Leaf check must be before recursion ends
✔ Subtract sum at each step
✔ Return OR of left and right

🔥 Alternative shorter version (clean code)
bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    
    sum -= root->val;
    
    if(!root->left && !root->right)
        return sum == 0;
    
    return hasPathSum(root->left, sum) ||
           hasPathSum(root->right, sum);
}