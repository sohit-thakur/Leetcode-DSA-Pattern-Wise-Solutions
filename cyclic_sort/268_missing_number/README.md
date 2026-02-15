📌 Missing Number – Cyclic Sort (Git Notes)
🔹 Problem

Given an array nums of size n containing distinct numbers in range [0, n], return the missing number.

Example:

Input:  [3,0,1]
Output: 2

🔹 Approach: Cyclic Sort
Idea

Since numbers are in range [0, n]

Every number x should be at index x

Place numbers at correct indices using swaps

🔹 Algorithm

Traverse array

For each index i:

If nums[i] < n

AND nums[i] != nums[nums[i]]

Swap nums[i] with nums[nums[i]]

Otherwise increment i

After placement, scan array:

First index where nums[i] != i → return i

If all indices match → return n

🔹 Code (C++)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i < n) {
            if(nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            } else {
                i++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i)
                return i;
        }

        return n;
    }
};

🔹 Why nums[i] < n ?

Because n itself has no valid index.

Example:

n = 3
valid indices = 0,1,2


If element = 3
We cannot place it at index 3 (out of bounds)

🔹 Time & Space Complexity

Time: O(n)

Space: O(1) (in-place)

Each element is swapped at most once

🔹 Important Interview Points

✔ Do NOT increment i after swap
✔ Always check nums[i] != nums[nums[i]]
✔ Prevent infinite loops
✔ Works only because numbers are in known range

🔹 When to Use Cyclic Sort

Use when:

Array contains numbers in range [0,n] or [1,n]

Need missing / duplicate numbers

Need O(n) time & O(1) space

🔥 Interview Tip

If interviewer asks:

Why not sort first?

Answer:

Sorting takes O(n log n)
Cyclic sort gives O(n)

Shows optimization thinking.