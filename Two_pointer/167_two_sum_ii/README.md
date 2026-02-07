# 167. Two Sum II – Input Array Is Sorted

## Difficulty
Medium

## Pattern
Two Pointer

## Problem Statement
Given a 1-indexed sorted array of integers, find two numbers such that they add up to a specific target.

## Approach
- Use two pointers: left and right
- Since the array is sorted:
  - If sum < target → move left pointer
  - If sum > target → move right pointer

## Algorithm
1. Initialize left = 0, right = n - 1
2. While left < right:
   - Calculate sum = numbers[left] + numbers[right]
   - Adjust pointers accordingly

## Time and Space Complexity
- Time: O(n)
- Space: O(1)

## Status
Solved ✅
