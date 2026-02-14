📌 Notes for Git (LeetCode 57 – Insert Interval)

Problem: Insert a new interval into a sorted, non-overlapping interval list and merge if necessary.

🔹 Approach Summary

This solution uses a three-phase linear scan:

1️⃣ Add non-overlapping intervals (before newInterval)

Condition:

intervals[i][1] < newInterval[0]


Meaning:
Current interval ends before new interval starts → no overlap.

2️⃣ Merge overlapping intervals

Condition:

intervals[i][0] <= newInterval[1]


Meaning:
Current interval starts before or at the end of new interval → overlap exists.

We update:

newInterval[0] = min(newInterval[0], intervals[i][0]);
newInterval[1] = max(newInterval[1], intervals[i][1]);


This expands newInterval to absorb overlaps.

3️⃣ Add remaining intervals (after merge)

All remaining intervals start after merged interval ends.

🔹 Why No Sorting?

Unlike LeetCode 56 (Merge Intervals), this problem guarantees:

Intervals are already sorted

Intervals are non-overlapping

So sorting is not required.

🔹 Time Complexity
O(n)


Single pass through intervals.

🔹 Space Complexity
O(n)


For result storage.

🔹 Key Observations

We modify newInterval instead of using result.back()

Only one merge chain is possible because input intervals do not overlap

Clean linear solution (no nested loops)

🔹 Edge Cases Covered

✔ Empty intervals
✔ Insert at beginning
✔ Insert at end
✔ New interval fully inside existing
✔ New interval fully covering multiple intervals