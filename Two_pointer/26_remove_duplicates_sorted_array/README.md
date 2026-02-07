
### Constraints
- `0 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `nums` is **sorted in non-decreasing order**.

---

## Solution Approach

1. **Two-Pointer Technique:**
   - `i` → points to the **last unique element** found.
   - `j` → scans the array to find the next unique element.

2. **Algorithm:**
   - Initialize `i = 0`, `j = 1`.
   - While `j < nums.size()`:
     - If `nums[i] == nums[j]`, it’s a duplicate → move `j` forward.
     - Else → `i++`, `nums[i] = nums[j]` → place the next unique element.
   - Return `i + 1` → the new length of unique elements.

3. **Edge Cases:**
   - Empty array (`nums.size() == 0`) → return 0.
   - All elements are unique → array remains unchanged.

---

## Complexity Analysis
- **Time Complexity:** `O(n)` — each element is checked at most once.  
- **Space Complexity:** `O(1)` — no extra array is used.

---

## C++ Implementation

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = i + 1;
        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
