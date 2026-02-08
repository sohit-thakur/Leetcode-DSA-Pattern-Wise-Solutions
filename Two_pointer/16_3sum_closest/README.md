🧩 Three Sum Closest — LeetCode (Medium)
🔹 Problem Statement

Given an integer array nums and an integer target, return the sum of three integers in nums such that the sum is closest to the target.

You may assume that exactly one solution exists.

💡 Approach (Sorting + Two Pointers)

This problem is solved optimally using the two-pointer technique after sorting the array.

Steps:

Sort the array

Enables efficient pointer movement

Fix one element (i)

Use two pointers:

j = i + 1

k = n - 1

Compute current sum:

Update the closest sum if it is nearer to the target

Move pointers:

If sum < target → increment j

Else → decrement k

⏱ Complexity Analysis

Time Complexity: O(n²)

Space Complexity: O(1) (excluding input)

🚀 Key Takeaways

Sorting helps reduce a 3-sum problem to a 2-sum style problem

Two pointers efficiently narrow down the closest sum

This approach is optimal and interview-standard

📌 Tags

Array Two Pointers Sorting LeetCode Medium Interview Question

💬 Interview One-Liner

“After sorting the array, I fix one element and use two pointers to find the closest sum in O(n²) time.”

