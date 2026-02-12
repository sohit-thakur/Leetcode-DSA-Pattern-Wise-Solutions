209. Minimum Size Subarray Sum
🧠 Problem Statement

Given an array of positive integers nums and an integer target, return the minimum length of a contiguous subarray whose sum is greater than or equal to target.

If no such subarray exists, return 0.

🔎 Key Observation

All numbers are positive

This guarantees:

Expanding the window → sum increases

Shrinking the window → sum decreases

Because of this monotonic behavior, we can use:

✅ Sliding Window (Two Pointers)

🚀 Optimal Approach — Variable Size Sliding Window
Algorithm

Initialize:

left = 0

sum = 0

minLength = INT_MAX

Expand window using right

When sum >= target:

Update minimum length

Shrink window from left

💻 Code (C++)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLength = INT_MAX;

        while (right < n) {
            sum += nums[right];

            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

⏱ Time & Space Complexity

Time Complexity: O(n)
Each element is visited at most twice (once by right, once by left)

Space Complexity: O(1)
Only constant variables used

📌 Why Sliding Window Works Here
Condition	Result
All elements positive	Window sum is monotonic
Sum increases when expanding	No need to revisit previous states
Shrinking reduces sum predictably	Optimal greedy approach works
❗ When Sliding Window Fails

If array contains negative numbers, this method fails.

Example:

nums = [2, -1, 2]


Then use:

Prefix Sum

Monotonic Deque (LeetCode 862)

🧩 Pattern Recognition (Interview Tip)

If problem says:

"Array contains only positive integers"

Immediately think:

Sliding Window

📝 Template for Variable Sliding Window
int left = 0;
for (int right = 0; right < n; right++) {
    sum += nums[right];

    while (condition satisfied) {
        update_answer();
        sum -= nums[left++];
    }
}

✅ Final Takeaway

This is a classic sliding window problem

Very common in interviews

Important for mastering two-pointer techniques