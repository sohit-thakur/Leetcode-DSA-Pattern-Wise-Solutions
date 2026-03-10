Maximum Average Subarray I — Notes
1. Problem

Given an integer array nums and an integer k, find the maximum average value of any subarray of size k.

Example

nums = [1,12,-5,-6,50,3]
k = 4

Subarrays of size 4:

[1,12,-5,-6]  → avg = 0.5
[12,-5,-6,50] → avg = 12.75
[-5,-6,50,3]  → avg = 10.5

Answer = 12.75

2. Brute Force Idea

Check every subarray of length k.

Steps

Start from index 0

Compute sum of k elements

Move to next index and repeat

Time Complexity

O(n*k)

This is inefficient for large n.

3. Optimal Approach — Sliding Window

Instead of recomputing the sum every time:

Compute sum of first k elements

Slide window by adding next element

Remove previous first element

Formula

newSum = oldSum + nums[j] - nums[j-k]

Then compute average:

average = sum / k
4. Algorithm Steps
Step 1

Compute sum of first k elements.

Step 2

Initialize

maxAvg = firstSum / k
Step 3

Slide the window

For each new element:

add nums[j]
remove nums[j-k]
calculate average
update maxAvg
5. Code Logic Explanation
First window
for(int i=0;i<k;i++){
    firstSum += nums[i];
}

Calculate first window sum.

Initial average
firstAvg = firstSum/k;
maxAvg = firstAvg;

Set initial maximum average.

Sliding window
for(int j=k;j<n;j++){
    firstSum += nums[j];
    firstSum -= nums[l];

Add new element and remove old element.

Update average
firstAvg = firstSum/k;
maxAvg = max(maxAvg,firstAvg);

Update maximum average.

Move left pointer
l++;
6. Complexity

Time Complexity

O(n)

Space Complexity

O(1)
7. Key Sliding Window Pattern

For fixed window size k

windowSum += nums[j]
windowSum -= nums[j-k]

This pattern appears in many problems.

8. Similar Sliding Window Problems

Good for practice:

Maximum Sum Subarray of Size K

Longest Substring Without Repeating Characters

Permutation in String

Minimum Size Subarray Sum

Sliding Window Maximum