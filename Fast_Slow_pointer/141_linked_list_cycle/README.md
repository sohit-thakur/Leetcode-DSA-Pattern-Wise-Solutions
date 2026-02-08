🔄 Linked List Cycle Detection (Floyd’s Tortoise and Hare)
📌 Problem Statement

Given the head of a singly linked list, determine if the linked list contains a cycle.

A cycle exists if there is some node in the list that can be reached again by continuously following the next pointer.

Return:

true → if there is a cycle

false → if there is no cycle

Constraints:

The number of nodes in the list is in the range [0, 10^4].

-10^5 <= Node.val <= 10^5

💡 Approach: Two Pointers (Floyd’s Tortoise and Hare)

Idea:

Use two pointers moving at different speeds:

slow → moves one step at a time

fast → moves two steps at a time

If the linked list has a cycle:

fast will eventually meet slow inside the cycle.

If the linked list has no cycle:

fast will reach nullptr (end of the list) and we return false.

Algorithm

Initialize:

ListNode* slow = head;
ListNode* fast = head;


Traverse the list:

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) return true; // cycle detected
}


If loop ends, return false → no cycle.

🧪 Example

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: tail connects to node index 1 → cycle exists


Example 2:

Input: head = [1,2], pos = 0
Output: true


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: no cycle

✅ C++ Implementation
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // move slow by 1
            fast = fast->next->next;    // move fast by 2

            if (slow == fast) return true; // cycle detected
        }

        return false; // no cycle
    }
};

⏱ Complexity Analysis
Metric	Complexity
Time	O(n)
Space	O(1)

✅ One pass, constant space solution using two pointers.

🎯 Key Insight

The fast pointer eventually laps the slow pointer if a cycle exists.

If no cycle exists, fast will reach the end of the list (nullptr).

This is also called Floyd’s Tortoise and Hare algorithm.