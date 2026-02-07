# 83. Remove Duplicates from Sorted List

## Difficulty
Easy

## Pattern
Linked List

## Problem Statement
Given the head of a sorted linked list, delete all duplicates such that each
element appears only once. Return the linked list sorted as well.

## Approach
- Since the list is already sorted, duplicate values will be adjacent.
- Traverse the list using a pointer.
- If the current node and next node have the same value:
  - Skip the next node.
- Otherwise, move the pointer forward.

## Algorithm
1. Start from the head node.
2. While current node and next node exist:
   - If `current->val == current->next->val`:
     - Set `current->next = current->next->next`
   - Else:
     - Move current to next node
3. Return head.

## Time and Space Complexity
- Time: **O(n)**
- Space: **O(1)**

## Edge Cases
- Empty list
- Single node list
- All nodes having same value

## Status
Solved ✅
