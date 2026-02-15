📌 448. Find All Numbers Disappeared in an Array

Problem from: LeetCode

🔹 Problem Statement

Given an array nums of size n where:

1 ≤ nums[i] ≤ n

Some elements appear twice

Some numbers in range [1, n] are missing

Return all missing numbers.

🔹 Example
Input:  [4,3,2,7,8,2,3,1]
Output: [5,6]

🔥 Approach: Cyclic Sort
Core Idea

Since numbers are in range [1, n],
each number x should be placed at:

index = x - 1


So we place elements at correct positions using swaps.

🔹 Algorithm
Step 1: Place Elements Correctly

For each index i:

correct = nums[i] - 1

If nums[i] != nums[correct]
    swap
Else
    i++


⚠ Important:

Do NOT increment i after swap

This prevents skipping incorrect values

Step 2: Find Missing Numbers

After cyclic placement:

If at index i:

nums[i] != i + 1


Then i + 1 is missing.

🔹 Code (C++)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int i = 0;

        // Cyclic Sort
        while(i < n) {
            int correct = nums[i] - 1;

            if(nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }

        // Collect missing numbers
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};

🔹 Why This Works

Duplicates prevent correct placement.

Example final state:

[1,2,3,4,3,2,7,8]


Indexes 4 and 5:

nums[4] != 5
nums[5] != 6


So:

5 and 6 are missing

🔹 Complexity Analysis

Time Complexity: O(n)

Space Complexity: O(1) (excluding result array)

Each element swapped at most once

🔹 Key Interview Points

✔ Works because numbers are in known range [1, n]
✔ Do NOT increment i after swap
✔ Always check nums[i] != nums[correct]
✔ Duplicates automatically stay in wrong positions

🔹 When to Use This Pattern

Use Cyclic Sort when:

Numbers are in range [1, n] or [0, n]

Need to find:

Missing numbers

Duplicate numbers

First missing positive

🚀 Pattern Recognition Rule

If problem says:

Numbers are in range 1 to n
Find missing / duplicate

→ Think Cyclic Sort first