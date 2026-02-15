📌 41. First Missing Positive
🔹 Problem

Given an unsorted integer array nums, return the smallest missing positive integer.

Constraints

O(n) time

O(1) extra space

🧠 Key Observations

Answer must lie in range [1, n+1]

Ignore:

Negative numbers

Zero

Numbers > n

Each number x belongs at index x - 1.

🔥 Approach — Modified Cyclic Sort
Step 1: Place valid numbers at correct index

Condition:

1 ≤ nums[i] ≤ n
AND
nums[i] != nums[nums[i] - 1]


Swap until correct placement.

Step 2: Find first index mismatch
if nums[i] != i + 1
    return i + 1


If all correct:

return n + 1

✅ Code
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n 
                && nums[i] != nums[nums[i] - 1]) {
                
                swap(nums[i], nums[nums[i] - 1]);
            } 
            else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

⚠️ Important Edge Case

Avoid this ❌:

int correct = nums[i] - 1;


If nums[i] == INT_MIN, it causes integer overflow.

Correct version uses short-circuit evaluation safely.

⏱ Complexity

Time: O(n)

Space: O(1)

Each element swapped at most once

🎯 Pattern Recognition

If question says:

Smallest missing positive

O(n) time

O(1) space

👉 Think Cyclic Sort (Index Mapping Technique)