📌 442. Find All Duplicates in an Array

Problem from: LeetCode

🔹 Problem Statement

Given an integer array nums of size n:

1 ≤ nums[i] ≤ n

Each element appears once or twice

Return all elements that appear twice

🔹 Example
Input:  [4,3,2,7,8,2,3,1]
Output: [2,3]

🔥 Approach: Cyclic Sort
Core Idea

Since numbers are in range [1, n]
Each number x belongs at:

index = x - 1


We place elements at their correct indices.

After placement:

If nums[i] != i + 1

Then nums[i] is a duplicate

🔹 Algorithm
Step 1: Cyclic Placement

For each index i:

correct = nums[i] - 1

If nums[i] != nums[correct]
    swap
Else
    i++


Important:

Do NOT increment i after swap

Prevents skipping incorrect elements

Step 2: Collect Duplicates

After cyclic sort:

If nums[i] != i + 1
    duplicate = nums[i]

🔹 Code (C++)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
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

        // Collect duplicates
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

🔍 Why This Works

Duplicates block proper placement.

Example final state:

[1,2,3,4,3,2,7,8]


Indexes:

4 → value 3 (should be 5)
5 → value 2 (should be 6)


So duplicates are:

3 and 2

⏱ Complexity

Time Complexity: O(n)

Space Complexity: O(1) (excluding result)

Each element swapped at most once

🔹 Key Interview Points

✔ Works because values are in range [1, n]
✔ Duplicate prevents correct placement
✔ No extra data structures used
✔ In-place modification

🔹 Pattern Recognition Rule

If problem states:

Numbers in range 1 to n
Find duplicates / missing

Think:

👉 Cyclic Sort