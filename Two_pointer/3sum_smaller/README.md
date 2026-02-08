Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

LintCode - Online Judge Solution

Candidate Written Test Screening, Team Competency Assessment, Programming Teaching Exercises, Online Exam Grading

WeChat for information


Example
Example1

Input:  nums = [-2,0,1,3], target = 2
Output: 2
Explanation:
Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Example2

Input: nums = [-2,0,-1,3], target = 2
Output: 3
Explanation:
Because there are three triplets which sums are less than 2:
[-2, 0, -1]
[-2, 0, 3]
[-2, -1, 3]
Challenge
Could you solve it in O(n2) runtime?



NOTE

🟢 3Sum Smaller (LintCode)
📌 Problem Statement

Given an array nums of n integers and an integer target, count the number of index triplets
(i, j, k) such that:

0 ≤ i < j < k < n
nums[i] + nums[j] + nums[k] < target

💡 Approach: Sorting + Two Pointers

Sort the array.

Fix one index i.

Use two pointers:

j = i + 1 (left pointer)

k = n - 1 (right pointer)

Check the sum of (i, j, k):

If sum < target, then all indices from j to k-1 form valid triplets.

Add (k - j) to the count.

Move j forward.

Otherwise, move k backward.

🧠 Key Insight

Because the array is sorted:

If nums[i] + nums[j] + nums[k] < target,
then all combinations (i, j, j+1 ... k-1) are also valid.

This allows counting multiple triplets in one step, reducing time complexity.

⏱ Time & Space Complexity
Complexity	Value
Time	O(n²)
Space	O(1) (excluding sort)