107. Binary Tree Level Order Traversal II
Problem Statement

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values.

This means traversal should start from the lowest level and end at the root.

Example:

Input:
        3
       / \
      9   20
         /  \
        15   7

Output:
[[15,7],[9,20],[3]]
Approach: Breadth-First Search (BFS) + Insert at Front

We use queue-based BFS traversal and insert each level at the beginning of the result vector.

This avoids using reverse() and directly builds bottom-up order.

Algorithm Steps

Create result vector to store final answer.

If root is NULL, return empty result.

Create queue and push root node.

While queue is not empty:

Get current level size.

Create level vector.

Process all nodes at current level:

Remove node from queue.

Add node value to level vector.

Push left child if exists.

Push right child if exists.

Insert level at beginning of result.

Return result.

Code Explanation
vector<vector<int>> result;

Stores final traversal.

queue<TreeNode*> q;
q.push(root);

Queue used for BFS traversal.

int size = q.size();

Represents number of nodes at current level.

TreeNode* node = q.front();
q.pop();

Removes node from queue.

level.push_back(node->val);

Adds node value to current level.

q.push(node->left);
q.push(node->right);

Push children into queue.

result.insert(result.begin(), level);

Inserts level at front to maintain bottom-up order.

Dry Run Example

Tree:

        3
       / \
      9   20
         /  \
        15   7

Execution flow:

Queue:

[3]
[9,20]
[15,7]
[]

Result builds as:

[[3]]
[[9,20],[3]]
[[15,7],[9,20],[3]]

Final Output:

[[15,7],[9,20],[3]]
Complexity Analysis

Time Complexity:

O(n)

Each node is visited once.

Space Complexity:

O(n)

Queue and result storage.

Key Concept

Important line:

result.insert(result.begin(), level);

This ensures:

Bottom-up order without reverse()
Pattern Recognition

Use this pattern for:

Reverse Level Order Traversal

Bottom View Problems

Tree BFS Variations

Comparison with Problem 102
Problem	Output Order
102	Top → Bottom
107	Bottom → Top
Interview Tip ⭐

Whenever question says:

bottom-up

reverse level order

Use:

BFS + insert at beginning