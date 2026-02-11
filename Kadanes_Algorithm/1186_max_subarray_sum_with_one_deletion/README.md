📌 LeetCode 1186 – Maximum Subarray Sum with One Deletion
🔍 Problem Summary

Given an integer array arr, choose a non-empty contiguous subarray.
You may delete at most one element from this subarray.
Return the maximum possible subarray sum.

💡 Key Insight

The best result at any index can come from:

a subarray without deletion (normal Kadane)

a subarray with one deletion already used

So we maintain two running Kadane states.

🧠 Algorithm (Kadane – Two States)

bestWithoutDeletion
→ maximum subarray sum ending at current index with no deletion

bestWithDeletion
→ maximum subarray sum ending at current index after one deletion

At each step:

Either extend the current subarray

Or delete the current element (only once)

✅ C++ Implementation
class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int bestWithoutDeletion = arr[0];
        int bestWithDeletion = 0;
        int answer = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int currentElement = arr[i];

            bestWithDeletion = max(
                bestWithDeletion + currentElement,
                bestWithoutDeletion
            );

            bestWithoutDeletion = max(
                currentElement,
                bestWithoutDeletion + currentElement
            );

            answer = max(
                answer,
                max(bestWithoutDeletion, bestWithDeletion)
            );
        }

        return answer;
    }
};

⏱ Complexity Analysis

Time Complexity: O(n)

Space Complexity: O(1)

⚠️ Important Notes

Deletion is optional

Subarray must remain non-empty

Works correctly for all-negative arrays

🏷️ Tags

Array · Kadane’s Algorithm · Dynamic Programming

🔑 One-Line Takeaway

This problem is solved using Kadane’s Algorithm with two running states: with and without deletion.