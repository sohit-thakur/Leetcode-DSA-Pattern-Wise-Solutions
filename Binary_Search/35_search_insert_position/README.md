Problem Context

You are implementing LeetCode 35: Search Insert Position.

Goal: return the index where target is found, or where it should be inserted to keep the array sorted.

Code with step-by-step notes
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();   // store the size of array
        int i = 0, j = n - 1;  // set pointers for binary search (inclusive range)

        // Binary search loop
        while(i <= j) {        // loop continues as long as i <= j
            int mid = i + (j - i) / 2;  // prevent integer overflow

            if(nums[mid] >= target) {   // if mid value is >= target
                j = mid - 1;            // move the right pointer left to narrow the search
            } else {
                i = mid + 1;            // move the left pointer right
            }
        }

        // At this point, i == position where target should be inserted
        return i;
    }
};
Why this works

Loop condition i <= j

Ensures every element is considered.

Stops when i has passed j, i.e., the insertion position is found.

nums[mid] >= target

If the middle element is equal or bigger, the potential insert position is at mid or to the left.

So, move j to mid - 1.

nums[mid] < target

If the middle element is smaller, the target must be to the right.

So, move i to mid + 1.

Return i

After the loop, i points to the correct insertion index.

Works for both:

Target exists in the array → returns its index.

Target doesn’t exist → returns the index where it can be inserted.

Example Traces
Example 1
nums = [1,3,5,6], target = 5

mid = 1 → nums[1] = 3 < 5 → i = 2

mid = 2 → nums[2] = 5 >= 5 → j = 1

Loop ends → i = 2 → correct index

Example 2
nums = [1,3,5,6], target = 2

mid = 1 → nums[1] = 3 >= 2 → j = 0

mid = 0 → nums[0] = 1 < 2 → i = 1

Loop ends → i = 1 → correct insertion index

✅ Key takeaways

i <= j ensures we don’t miss any elements.

Returning i after the loop gives the exact insert position.

This is a classic lower_bound-style binary search.