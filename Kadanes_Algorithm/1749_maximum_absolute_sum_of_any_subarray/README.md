Here are clean, concise GitHub-ready notes you can paste directly into your repository (README or solution notes).

📌 LeetCode 1749 – Maximum Absolute Sum of Any Subarray
🔍 Problem Summary

Given an integer array nums, find the maximum absolute sum of any (non-empty) subarray.

💡 Key Insight

The maximum absolute subarray sum must be either:

the maximum subarray sum, or

the minimum (most negative) subarray sum

So the answer is:

max( |maxSubarraySum| , |minSubarraySum| )

🚀 Approach (Kadane’s Algorithm – Dual Tracking)

We modify Kadane’s Algorithm to track:

currMax → maximum subarray sum ending at current index

currMin → minimum subarray sum ending at current index

And maintain global values:

totalMax → overall maximum subarray sum

totalMin → overall minimum subarray sum

🧠 Algorithm Steps

Initialize all variables with nums[0]

Traverse the array from index 1

At each index:

Update currMax and currMin

Update totalMax and totalMin

Return max(totalMax, abs(totalMin))

✅ C++ Implementation
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currMax = nums[0];
        int currMin = nums[0];
        int totalMax = nums[0];
        int totalMin = nums[0];

        for (int i = 1; i < n; i++) {
            currMax = max(nums[i], currMax + nums[i]);
            currMin = min(nums[i], currMin + nums[i]);

            totalMax = max(totalMax, currMax);
            totalMin = min(totalMin, currMin);
        }

        return max(totalMax, abs(totalMin));
    }
};

⏱ Complexity Analysis

Time Complexity: O(n)

Space Complexity: O(1)

⚠️ Important Notes

Initializing with nums[0] is crucial to handle all-negative arrays

This avoids incorrect results when the best subarray starts at index 0

🏷️ Tags

Array · Kadane’s Algorithm · Dynamic Programming