📌 LeetCode 113. Path Sum II — Git Notes (Your Code Explanation)
🧾 Problem Summary

Return all root-to-leaf paths where the sum of node values equals targetSum.

✔ Path must start from root
✔ Path must end at leaf
✔ Return actual paths, not just true/false

🧠 Approach Used: DFS + Backtracking Style

You maintain:

sum → current path sum

temp → current path nodes

result → stores all valid paths

💻 Your Code (Annotated)
class Solution {
     vector<vector<int>> result;

public:

     void fill(TreeNode* root, int sum, vector<int> temp, int targetSum){

        // Base case
        if(!root) {
            return;
        }

        // Add current node to sum
        sum += root->val;

        // Add node to path
        temp.push_back(root->val);

        // Leaf node check
        if(!root->left && !root->right){

            // Valid path found
            if(sum == targetSum){
                result.push_back(temp);
            }
            return;
        }

        // Explore left subtree
        fill(root->left, sum, temp, targetSum);

        // Explore right subtree
        fill(root->right, sum, temp, targetSum);
     }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> temp;
        int sum = 0;

        fill(root, sum, temp, targetSum);

        return result;
    }
};
🌳 Example Dry Run

Tree:

       5
      / \
     4   8
    /   / \
   11  13  4
  /  \     \
 7    2     1

targetSum = 22

Valid paths:

[5,4,11,2]
[5,8,4,5]
🔁 Recursive Flow
fill(root, sum, temp)

add node->val

if leaf:
   check sum
else:
   go left
   go right
⏱️ Complexity Analysis
Time Complexity
O(N)

Visit each node once

Space Complexity
O(H)

Recursion depth

Worst case:

O(N)
⚠️ Important Optimization (Better Approach)

Your current code copies vector every call:

vector<int> temp

Better approach → use reference + backtracking

🔥 Optimized Version (Recommended in Interviews)
class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* root, int targetSum, vector<int>& temp) {

        if(!root) return;

        temp.push_back(root->val);

        if(!root->left && !root->right && targetSum == root->val){
            result.push_back(temp);
        }

        dfs(root->left, targetSum - root->val, temp);
        dfs(root->right, targetSum - root->val, temp);

        temp.pop_back(); // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> temp;

        dfs(root, targetSum, temp);

        return result;
    }
};
🧠 Why Backtracking is Better

Instead of copying vector:

copy cost = O(N)

Backtracking:

push → explore → pop

More efficient

🧾 Interview Key Points

✔ DFS traversal
✔ Root-to-leaf condition
✔ Store full path
✔ Backtracking improves efficiency
✔ Use reference vector

🧩 Pattern Category

This belongs to:

Binary Tree + DFS + Backtracking

Same pattern used in:

Path Sum II

Subsets

Combination Sum

Permutations