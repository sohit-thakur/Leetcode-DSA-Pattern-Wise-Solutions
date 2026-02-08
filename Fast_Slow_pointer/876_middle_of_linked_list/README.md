🟢 Find Middle of a Linked List
📌 Problem Statement

Given the head of a singly linked list, return the middle node of the list.

If there are two middle nodes, return the second middle node.

You must do it in one pass and O(1) space.

Constraints:

Number of nodes in the list: [1, 100]

Node values: 1 <= Node.val <= 100

💡 Approach: Slow and Fast Pointers

Idea:

Use two pointers:

slow → moves one step at a time

fast → moves two steps at a time

When fast reaches the end of the list (nullptr), slow will be at the middle node.

Algorithm Steps

Initialize:

ListNode* slow = head;
ListNode* fast = head;


Traverse the list:

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}


Return slow → middle node.

🧪 Example

Example 1:

Input: head = [1,2,3,4,5]
Output: Node with value 3
Explanation: Middle node is 3


Example 2:

Input: head = [1,2,3,4,5,6]
Output: Node with value 4
Explanation: Second middle node is 4

✅ C++ Implementation
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

⏱ Complexity Analysis
Metric	Complexity
Time	O(n)
Space	O(1)

✅ One pass, constant space solution using slow and fast pointers.

🎯 Key Insight

The fast pointer moves twice as fast as slow.

When fast reaches the end, slow will naturally be at the middle node.

Works for odd and even length lists (returns second middle in even case).