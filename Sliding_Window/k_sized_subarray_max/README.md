Final One-Line Reason (Interview Ready)

We don’t use a queue because it cannot remove elements from the back or maintain a monotonic order, which is required to get the sliding window maximum in O(n) time.

🪟 Sliding Window Maximum (Deque Approach)

Problem
Given an array arr of size n and an integer k, find the maximum element in every contiguous subarray of size k.

💡 Key Idea

We use a deque (double-ended queue) to efficiently track indices of useful elements for each sliding window.

The deque always maintains:

Indices in decreasing order of values

The front of the deque stores the index of the maximum element of the current window

🧠 Why Deque?

Allows O(1) insertion and deletion from both ends

Avoids recomputation of max for every window

Ensures total time complexity stays O(n)

🔁 Algorithm (Step-by-Step)

For each index i from 0 to n-1:

Remove out-of-window indices

if (!dq.empty() && dq.front() == i - k)
    dq.pop_front();


Maintain decreasing order

Remove all indices from the back whose values are ≤ arr[i]

while (!dq.empty() && arr[dq.back()] <= arr[i])
    dq.pop_back();


Add current index

dq.push_back(i);


Store maximum when window is complete

if (i >= k - 1)
    ans.push_back(arr[dq.front()]);

📌 Important Observations

❌ Deque does NOT store values → it stores indices

✅ Front of deque is always the maximum for the current window

🔄 Each index is added and removed at most once

🧪 Dry Run Example

Input

arr = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3


Windows & Max

[1, 3, -1]  → 3
[3, -1, -3] → 3
[-1, -3, 5] → 5
[-3, 5, 3]  → 5
[5, 3, 6]   → 6
[3, 6, 7]   → 7


Output

[3, 3, 5, 5, 6, 7]

⏱️ Complexity Analysis
Metric	Value
Time	O(n)
Space	O(k) (deque stores at most k indices)
🧩 Pattern Used

Sliding Window

Monotonic Deque

🚀 When to Use This Pattern?

Fixed-size window problems

Max / Min in subarrays

Stock span, Next Greater Element variants