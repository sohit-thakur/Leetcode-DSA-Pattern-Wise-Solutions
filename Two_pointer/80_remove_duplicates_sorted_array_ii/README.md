
### Constraints
- `1 <= nums.length <= 3 * 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in **non-decreasing order**.

---

## Solution Approach

1. **Two-Pointer Technique:**  
   - `i` → last index of the allowed portion of the array (keeps at most 2 of each element).  
   - `j` → scans through the array.  

2. **Algorithm:**  
   - Allow the first **two elements** by default (`i = 1`).  
   - Iterate `j` from index 2 to `nums.size() - 1`:  
     - If `nums[j] != nums[i - 1]` → place `nums[j]` at `nums[i+1]` and increment `i`.  
   - Return `i + 1` → the new length of the array.

3. **Edge Cases:**  
   - Array size ≤ 2 → return `nums.size()` (already allowed).  

---

## Complexity Analysis
- **Time Complexity:** `O(n)` — each element is checked once.  
- **Space Complexity:** `O(1)` — in-place modification, no extra array used.  

---

## C++ Implementation

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int i = 1; // last allowed index
        for (int j = 2; j < nums.size(); j++) {
            if (nums[j] != nums[i - 1]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
