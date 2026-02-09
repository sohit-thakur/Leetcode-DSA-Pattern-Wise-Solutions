# Find First and Last Position of Element in Sorted Array

This repository contains a **C++ solution** to the LeetCode problem:

**[LeetCode 34 – Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)**

---

## Problem Description

Given an array of integers `nums` sorted in non-decreasing order and a `target` value, find the starting and ending position of the target in the array.

- If the target is not found in the array, return `[-1, -1]`.
- Your solution should run in **O(log n)** time.

### Example

```text
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Approach
We use binary search to find the first and last occurrence of the target:

First Occurrence

Initialize left = 0 and right = n - 1.

Use binary search:

If nums[mid] == target, store mid as first and move right = mid - 1 to search left side.

If nums[mid] < target, search right side.

If nums[mid] > target, search left side.

Last Occurrence

Initialize left = 0 and right = n - 1.

Use binary search:

If nums[mid] == target, store mid as second and move left = mid + 1 to search right side.

If nums[mid] > target, search left side.

If nums[mid] < target, search right side.

This gives O(log n) time complexity.

C++ Implementation
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int second = -1;
        int left = 0, right = n - 1;

        // Find first occurrence
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Find last occurrence
        left = 0;
        right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                second = mid;
                left = mid + 1;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return {first, second};
    }
};
Complexity Analysis
Time Complexity: O(log n) for each binary search → total O(log n)

Space Complexity: O(1)

Tags
Binary Search | Array | LeetCode 34 | C++

