🧩 3Sum — LeetCode (Medium)
🔹 Problem Statement

Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]] such that:

i ≠ j ≠ k

nums[i] + nums[j] + nums[k] == 0

The solution set must not contain duplicate triplets.

💡 Approach (Optimized)

We use a Sorting + Two Pointer technique to reduce time complexity.

Steps:

Sort the array

Helps in avoiding duplicates

Enables two-pointer traversal

Fix one element (i)

Iterate from 0 to n-3

Skip duplicate values for i

Two-pointer search

Set j = i + 1 and k = n - 1

Adjust pointers based on sum:

sum == 0 → store triplet & move both pointers

sum < 0 → move j forward

sum > 0 → move k backward

Skip duplicates

Avoid repeating the same triplet in the result



⏱ Complexity Analysis

Time Complexity: O(n²)

Space Complexity: O(1) (excluding output storage)

🚀 Key Takeaways

Sorting enables efficient two-pointer traversal

Duplicate handling is critical for correctness

This approach is interview-acceptable and scales well