📌 Indexes of Subarray Sum (Sliding Window)
🧠 Problem Summary

Given an array of non-negative integers, find the first continuous subarray whose sum equals a given target.
Return the 1-based indices of that subarray.
If no such subarray exists, return [-1].

✅ Approach: Sliding Window / Two Pointers

This approach works efficiently because all elements are non-negative.

Key Idea

Use two pointers: left and right

Expand the window by moving right

Shrink the window from left if the sum exceeds target

The first valid window is the answer

🧾 Implementation (C++)
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int sumCount = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sumCount += arr[right];

            while (sumCount > target && left <= right) {
                sumCount -= arr[left];
                left++;
            }

            if (sumCount == target) {
                return {left + 1, right + 1}; // 1-based indexing
            }
        }
        return {-1};
    }
};

🔍 Example

Input

arr = [1, 2, 3, 7, 5]
target = 12


Output

[2, 4]


Explanation
2 + 3 + 7 = 12

⏱️ Complexity Analysis
Metric	Value
Time Complexity	O(n)
Space Complexity	O(1)
⚠️ Important Notes

This solution only works for non-negative integers

Returns the leftmost valid subarray

Uses 1-based indexing as required by GFG

🏷️ Tags

Array · Sliding Window · Two Pointers · Greedy