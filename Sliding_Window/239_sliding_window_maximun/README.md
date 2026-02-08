LeetCode 239 – Sliding Window Maximum

Problem:
Given an integer array nums and a window size k, find the maximum value in each sliding window of size k.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3  
Output: [3,3,5,5,6,7]

Approach: Sliding Window + Monotonic Deque

Use a deque to store indices of elements in decreasing order.

Front of the deque always contains the maximum for the current window.

Steps for each element:

Remove indices out of the current window (older than i-k+1).

Remove elements from back if they are smaller than the current element.

Add current index to the back of deque.

If window has reached size k, add nums[deque.front()] to the result.

Step-by-step deque example

Input: nums = [1,3,-1,-3,5], k = 3

i	Window	Deque indices	Deque values	Max
0	[1]	[0]	[1]	-
1	[1,3]	[1]	[3]	-
2	[1,3,-1]	[1,2]	[3,-1]	3
3	[3,-1,-3]	[1,2,3]	[3,-1,-3]	3
4	[-1,-3,5]	[4]	[5]	5

Explanation:

Deque always maintains potential maximums in the current window.

Front of deque → current maximum.

As the window slides, we remove indices out of window and elements smaller than current.

Code
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> d;
        
        for (int i = 0; i < n; i++) {
            if (!d.empty() && d.front() <= i - k)
                d.pop_front();
            
            while (!d.empty() && nums[i] >= nums[d.back()])
                d.pop_back();
            
            d.push_back(i);
            
            if (i >= k - 1)
                res.push_back(nums[d.front()]);
        }
        
        return res;
    }
};

Complexity

Time: O(n) → each element enters/exits deque once

Space: O(k) → deque stores at most k indices

Pattern

Sliding Window + Monotonic Queue / Deque

Useful for: max/min in a window, extreme-value subarrays, window constraint problems.