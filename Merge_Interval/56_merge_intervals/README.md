📌 Notes for Git (LeetCode 56 – Merge Intervals)

Problem: Given a collection of intervals, merge all overlapping intervals.

🔹 Approach Overview
1️⃣ Sort the intervals
sort(intervals.begin(), intervals.end());


Sorting ensures intervals are arranged by starting time.
This makes overlap detection straightforward.

2️⃣ Initialize result with first interval
ans.push_back(intervals[0]);


We use ans to store merged intervals.

3️⃣ Iterate and merge

For each interval:

if(ans.back()[1] >= intervals[i][0])


Meaning:
Last merged interval overlaps with current interval.

Merge by updating the end:

ans.back()[1] = max(ans.back()[1], intervals[i][1]);


Otherwise:

ans.push_back(intervals[i]);


Add as a new non-overlapping interval.

🔹 Key Concept

ans.back() always represents the last merged interval.

We only compare:

Last merged interval  vs  Current interval


Because after sorting, only adjacent intervals can overlap.

🔹 Time Complexity
O(n log n)


Sorting → O(n log n)

Single pass merge → O(n)

🔹 Space Complexity
O(n)


For storing merged intervals.

🔹 Why Sorting Is Required Here

Unlike Insert Interval (57), here:

Intervals may be unsorted

Intervals may overlap arbitrarily

Sorting guarantees proper merging.

🔹 Edge Cases Handled

✔ Empty input
✔ Fully overlapping intervals
✔ Chain overlaps (e.g., [1,4], [2,5], [3,6])
✔ Already non-overlapping

🔹 Professional Git Commit Message (Short Version)
Implemented interval merging using sorting and linear scan.
Used vector::back() for efficient overlap detection and in-place merging.
Time: O(n log n), Space: O(n).

