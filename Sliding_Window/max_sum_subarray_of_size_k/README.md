Max Sum Subarray of Size K

A C++ implementation to find the maximum sum of any contiguous subarray of size k using the Sliding Window technique.

📝 Problem Description

Given an array of integers arr and an integer k, return the maximum sum of any contiguous subarray of size exactly k.

Example
Input:
arr = [2, 1, 5, 1, 3, 2]
k = 3

Output:
9


Explanation:
Subarray [5, 1, 3] gives the maximum sum = 9.

🚀 Approach — Sliding Window Technique

Instead of recalculating the sum of every subarray of size k (which would take O(n × k) time), we use a Sliding Window approach to achieve O(n) time complexity.

Steps:

Initialize
Calculate the sum of the first k elements.

Slide the Window
Move the window one element at a time toward the right.

Update the Sum Efficiently

Add the new element entering the window

Subtract the element leaving the window

Track Maximum
Keep updating the maximum sum found so far.

📊 Complexity Analysis
Type	Complexity
Time Complexity	O(n)
Space Complexity	O(1)

We traverse the array only once.

No extra data structures are used.

💻 C++ Implementation
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return 0; // Edge case

        int l = 0;
        int maxCount = 0;
        int currentWindowSum = 0;

        // Step 1: Calculate first window sum
        for(int i = 0; i < k; i++) {
            currentWindowSum += arr[i];
        }

        maxCount = currentWindowSum;

        // Step 2: Slide the window
        for(int i = k; i < n; i++) {
            currentWindowSum += arr[i] - arr[l];
            maxCount = max(maxCount, currentWindowSum);
            l++;
        }

        return maxCount;
    }
};

🧠 Key Concepts

Sliding Window Pattern

Efficient Window Update

Fixed-Size Subarray

Optimization from O(n × k) → O(n)

📌 Best Practice for DSA Repositories

When adding similar problems:

Keep one problem per file

Mention pattern used (Sliding Window, Two Pointers, etc.)

Add time and space complexity

Use meaningful commit messages:

feat: add sliding window solution for max subarray sum
