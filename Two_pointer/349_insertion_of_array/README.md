🟢 LeetCode 349 — Intersection of Two Arrays
1️⃣ Hash Set Approach (Best & Preferred)
Idea

Store elements of first array in a set

Traverse second array

If element exists in set → add to answer and erase to ensure uniqueness

Complexity

Time: O(n + m)

Space: O(n)

When to use

✔ Arrays are unsorted
✔ Only unique elements required
✔ Optimal and clean solution

2️⃣ Sorting + Two Pointers
Idea

Sort both arrays

Use two pointers to compare elements

Add element when equal

Skip duplicates to maintain uniqueness

Complexity

Time: O(n log n)

Space: O(1)

When to use

✔ Arrays already sorted
✔ Space optimization required

❌ Map Approach (Not Recommended)
Reason

Frequency counting not required

Set already ensures uniqueness

Extra overhead without benefit

🎯 Interview One-Liner

“Since only unique elements are needed, a set is the most optimal approach.”