🔄 Linked List Cycle II – Detect Start of Cycle
📌 Problem Statement

Given the head of a singly linked list, return the node where the cycle begins.

If there is no cycle, return nullptr.

A cycle exists if a node’s next pointer eventually points back to a previous node in the list.

Constraints:

Number of nodes: [0, 10⁴]

Node values: -10⁵ <= Node.val <= 10⁵

💡 Approach: Floyd’s Tortoise and Hare (Two Pointers)

Algorithm Steps:

Use two pointers, slow and fast:

slow moves one step at a time

fast moves two steps at a time

If slow == fast → cycle detected.

If no cycle (fast reaches nullptr) → return nullptr.

To find the start of the cycle:

Reset slow to head

Move both slow and fast one step at a time

The point where they meet is the cycle start.

🧪 Example

Input:

head = [3,2,0,-4], pos = 1


Output:

Node with value 2


Explanation:

Tail connects to node index 1 → cycle starts at node with value 2.

✅ C++ Implementation
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        // No cycle
        if (fast == nullptr || fast->next == nullptr) return nullptr;

        // Step 2: Find start of cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

⏱ Complexity Analysis
Metric	Complexity
Time	O(n)
Space	O(1)

✅ Optimal solution using two pointers and constant space.

🎯 Key Insight

Fast and slow pointers meet inside the cycle → confirms cycle exists.

Moving both pointers at same speed from head and meeting point → identifies start of the cycle.