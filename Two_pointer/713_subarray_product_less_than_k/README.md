713. Subarray Product Less Than K
📌 Problem Statement

Given an array of positive integers nums and an integer k, return the number of contiguous subarrays where the product of all elements is less than k.

Constraints:

All elements in nums are positive integers.

0 ≤ nums.length ≤ 10⁵

0 ≤ nums[i] < 1000

0 ≤ k < 10⁶

💡 Approach: Two Pointers / Sliding Window

Idea:

Use two pointers (left and right) to maintain a window [left..right] where the product of elements < k.

Since all numbers are positive, the product monotonically increases when adding numbers to the right.

If product >= k, shrink the window from the left.

For each right, all subarrays ending at right are valid:

number of subarrays = right - left + 1

🔑 Steps

Initialize: left = 0, product = 1, count = 0.

Iterate right from 0 to n-1:

Multiply product by nums[right].

While product >= k, divide by nums[left] and move left++.

Add (right - left + 1) to count.

Return count.

🧪 Example

Input:

nums = [10, 5, 2, 6], k = 100


Valid Subarrays:

[10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]


Output:

8

✅ C++ Implementation
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // edge case: no valid subarray

        int left = 0, count = 0;
        long long product = 1;

        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];

            // shrink the window if product >= k
            while (product >= k && left <= right) {
                product /= nums[left];
                left++;
            }

            // all subarrays ending at 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }
};

⏱ Complexity Analysis
Metric	Complexity
Time	O(n)
Space	O(1)
🎯 Key Insight

Every time the product of the window [left..right] is less than k, all subarrays ending at right are valid. Using two pointers, we efficiently expand and shrink the window to count all subarrays in O(n) time.

📌 Interview Tip

This is a sliding window problem using two pointers.

Always visualize the window [left..right] and how it moves.