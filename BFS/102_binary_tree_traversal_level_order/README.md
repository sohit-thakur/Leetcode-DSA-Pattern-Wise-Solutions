Problem Statement

Given the root of a binary tree, return the level order traversal of its nodes' values (i.e., from left to right, level by level).

Example:

Input:
    3
   / \
  9  20
     / \
    15  7

Output:
[[3], [9,20], [15,7]]
Approach: Breadth-First Search (BFS)

This problem is solved using Breadth-First Search (BFS) with a queue.

BFS processes nodes level by level, which matches the requirement.

Algorithm Steps

Create a result vector to store final output.

If root is NULL, return empty result.

Create a queue and push root node.

Run loop while queue is not empty:

Get current queue size → number of nodes in current level.

Create level vector.

Process all nodes of this level:

Remove node from queue.

Add node value to level vector.

Push left child if exists.

Push right child if exists.

Add level vector to result.

Return result.

Code Explanation
vector<vector<int>> result;

Stores final answer.

queue<TreeNode*> q;
q.push(root);

Queue used for BFS traversal.

while(!q.empty())

Runs until all nodes are processed.

int size = q.size();

Number of nodes at current level.

TreeNode* node = q.front();
q.pop();

Remove node from queue.

level.push_back(node->val);

Store node value.

q.push(node->left);
q.push(node->right);

Add children to queue.

result.push_back(level);

Store completed level.

Dry Run Summary

Queue flow:

[3]
[9,20]
[15,7]
[]

Result builds as:

[[3]]
[[3],[9,20]]
[[3],[9,20],[15,7]]
Complexity Analysis

Time Complexity:

O(n)

Each node is visited once.

Space Complexity:

O(n)

Queue stores nodes.

Key Concept

Important line:

int size = q.size();

This ensures:

Each iteration processes exactly one level
Pattern Recognition

Use this pattern for:

Level Order Traversal

Level Order Reverse

Zigzag Traversal

Right Side View

Minimum Depth of Tree

Interview Tip ⭐

Whenever question says:

level order

level by level

breadth first

Think:

BFS + Queue