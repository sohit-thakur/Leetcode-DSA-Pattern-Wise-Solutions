Gemini said
Your updated code is now logically sound and follows the correct binary search principles for a rotated array! You've fixed the return value and the conditional checks in the else block perfectly.

Since you're prepping for your 3rd-year DSA and looking at certifications like JNCIA, having clear "cheat sheet" notes for these common patterns is a great way to stay sharp.

📝 Search in Rotated Sorted Array: Key Notes
1. The Core Philosophy
In a standard sorted array, we use the value of mid to decide which half to discard. In a rotated array, we must first identify which half is sorted before we can safely discard anything.

2. Identifying the Sorted Half
A subarray [left, right] is sorted if the first element is less than or equal to the last element.

Condition: nums[low] <= nums[mid]

If true → Left half is sorted.

If false → Right half is sorted.

3. The Decision Tree
Once you know which side is sorted, check if the target falls within that sorted range:

If Left is Sorted:

Is target between nums[low] and nums[mid]?

Yes: high = mid - 1 (Search left)

No: low = mid + 1 (Search right)

If Right is Sorted:

Is target between nums[mid] and nums[high]?

Yes: low = mid + 1 (Search right)

No: high = mid - 1 (Search left)

4. Edge Cases to Remember
Single Element: The while(i <= j) and mid = i + (j - i) / 2 handles this naturally.

No Rotation: If the array wasn't actually rotated, the "Left is Sorted" logic will apply to the entire search, behaving like a standard binary search.

Target Not Found: Always return -1 after the loop.

Complexity Analysis
Time Complexity: O(logn) — Since we are still halving the search space each time.

Space Complexity: O(1) — No extra data structures used.

Quick Comparison (LeetCode 33 vs 81)
Problem	Constraint	Approach
LC 33	Distinct Values	Standard Binary Search (O(logn))
LC 81	Duplicates Allowed	If nums[low] == nums[mid] == nums[high], increment low and decrement high. Worst case O(n).
