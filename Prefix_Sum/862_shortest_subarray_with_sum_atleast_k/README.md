📌 862 – Shortest Subarray with Sum at Least K
🔹 Category

Prefix Sum

Monotonic Deque

Hard

🔹 Problem Summary

Given an integer array nums (can contain negatives) and integer k,
return the length of shortest non-empty subarray with sum ≥ k.

If no such subarray exists → return -1.

🔹 Why Sliding Window Fails

Sliding window works only when:

All numbers are positive

Sum increases when window expands

Here:

Numbers can be negative

Sum can decrease
→ Two pointer fails

🔹 Core Idea

Use Prefix Sum:

prefix[i] = sum of first i elements


Subarray sum:

prefix[j] - prefix[i] ≥ k


Rearranged:

prefix[i] ≤ prefix[j] - k


For each j, find smallest valid i.

🔹 Why Deque?

We maintain indices of prefix array in:

Monotonic Increasing Order of prefix values

Operation 1: Check Valid Subarray
while prefix[i] - prefix[dq.front()] >= k


Update answer

Pop front

Ensures shortest length

Operation 2: Maintain Monotonic Order
while prefix[i] <= prefix[dq.back()]


Pop back

Larger prefix is useless

🔹 Final Code
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        deque<int> dq;
        int minLength = n+1;

        for(int i=0;i<=n;i++){
            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefix[i] <= prefix[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return (minLength==n+1) ? -1 : minLength;
    }
};

🔹 Complexity

Time: O(n)

Space: O(n)

Each index:

Pushed once

Popped at most once

Total operations ≤ 2n

🔹 Pattern Recognition Trick

If you see:

Negative numbers

Shortest/longest subarray

Condition like sum ≥ k

Subarray difference expression

Think:

Prefix Sum + Monotonic Deque

🔹 Interview Explanation (Short)

"We convert subarray sum to prefix difference and maintain a monotonic deque of candidate indices to find the shortest valid window in O(n) time."