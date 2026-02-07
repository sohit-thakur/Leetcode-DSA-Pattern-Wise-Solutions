# 1. Two Sum

## Difficulty
Easy

## Pattern
Hash Map

## Problem Statement
Given an array of integers `nums` and an integer `target`, return the indices
of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

## Approach
- Use a hash map to store each number and its index.
- For each element, calculate the remaining value needed to reach the target.
- If the remaining value exists in the map, return both indices.

## Algorithm
1. Initialize an empty hash map.
2. Traverse the array:
   - Compute `rem = target - nums[i]`
   - If `rem` exists in the map → solution found
   - Otherwise, store `nums[i]` with its index
3. Return the result.

## Time and Space Complexity
- Time: **O(n)**
- Space: **O(n)**

## Edge Cases
- Negative numbers
- Target = 0
- Duplicate values

## Status
Solved ✅
