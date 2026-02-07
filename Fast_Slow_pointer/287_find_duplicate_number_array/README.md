
---

## Constraints
- `1 <= n <= 10^5`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
- Exactly **one number is duplicated**, possibly more than once

---

## Solution Approach  
### Fast & Slow Pointer (Floyd’s Tortoise & Hare)

This problem can be solved using **cycle detection**.

### Key Insight
- Treat the array as a **linked list**
- Each index points to `nums[index]`
- Due to the duplicate, a **cycle must exist**
- The **entry point of the cycle** is the duplicate number

---

## Algorithm Steps

1. Initialize two pointers:
   - `slow = nums[0]`
   - `fast = nums[0]`
2. Move:
   - `slow` by 1 step → `slow = nums[slow]`
   - `fast` by 2 steps → `fast = nums[nums[fast]]`
3. When they meet, a cycle is detected.
4. Reset `slow` to `nums[0]`.
5. Move both pointers **one step at a time**.
6. The point where they meet again is the **duplicate number**.

---

## C++ Implementation

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Detect cycle
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Step 2: Find entry point of cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // duplicate number
    }
};
