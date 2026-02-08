🟢 Sort Colors (LeetCode / Dutch National Flag Problem)
📌 Problem Statement

Given an array nums with n integers where each integer is 0, 1, or 2, sort the array in-place so that:

all 0s come first, then all 1s, then all 2s


Do not use the library sort function.

Must be done in one pass with constant space.

💡 Approach: Dutch National Flag Algorithm (Three Pointers)

Idea:

Use three pointers:

i → next position for 0

j → current element under consideration

k → next position for 2

Traverse the array with j and do:

If nums[j] == 0 → swap nums[i] and nums[j], increment i and j.

If nums[j] == 1 → just move j++.

If nums[j] == 2 → swap nums[j] and nums[k], decrement k. (Do not increment j here.)

This ensures 0s go left, 2s go right, 1s stay in middle.

🧪 Example

Input:

nums = [2,0,2,1,1,0]


Output:

[0,0,1,1,2,2]


Explanation:

All 0s are at the start

All 1s in the middle

All 2s at the end

✅ C++ Implementation
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;            // next position for 0
        int j = 0;            // current element
        int k = nums.size() - 1; // next position for 2

        while (j <= k) {
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } 
            else if (nums[j] == 1) {
                j++;
            } 
            else { // nums[j] == 2
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }
};

⏱ Complexity Analysis
Metric	Complexity
Time	O(n)
Space	O(1)

✅ One pass solution with constant space.

🎯 Key Insight

By keeping three pointers and swapping in place:

0s move to the left (i)

1s stay in the middle (j)

2s move to the right (k)
We can sort the array efficiently without extra memory or multiple passes.