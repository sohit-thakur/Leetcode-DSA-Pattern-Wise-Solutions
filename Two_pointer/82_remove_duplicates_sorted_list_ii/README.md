Input:  1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
Output: 1 -> 2 -> 5

Input:  1 -> 1 -> 1 -> 2 -> 3
Output: 2 -> 3


### Constraints
- The number of nodes in the list is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is guaranteed to be sorted in ascending order.

---

## Solution Approach

1. **Pointers Used:**
   - `curr` → Current node being checked.
   - `prev` → Last confirmed unique node.

2. **Algorithm:**
   - Iterate through the list:
     - If `curr` has duplicates (`curr->val == curr->next->val`):
       - Skip all nodes with that value using a `while` loop.
       - Connect `prev->next` to the first non-duplicate node.
       - If duplicates are at the head (`prev == nullptr`), update `head = curr`.
     - If no duplicates:
       - Move `prev = curr`
       - Move `curr = curr->next`

3. **Edge Cases:**
   - Duplicates at the head
   - All nodes are duplicates
   - No duplicates at all

---

## Complexity Analysis
- **Time Complexity:** `O(n)` — each node is visited once.
- **Space Complexity:** `O(1)` — only constant extra pointers used.

---

## C++ Implementation

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                int dup = curr->val;
                while (curr && curr->val == dup) {
                    curr = curr->next;
                }
                if (prev) {
                    prev->next = curr;
                } else {
                    head = curr;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
