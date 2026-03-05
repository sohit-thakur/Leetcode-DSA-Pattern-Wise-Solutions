Problem

You are given:

startTime[i]
endTime[i]
profit[i]

Each represents a job.

Goal:

Select non-overlapping jobs
so that total profit is maximum

Condition:

endTime[i] <= startTime[j]
Approach

Technique used:

Sorting
+ 
Binary Search
+
Dynamic Programming (Memoization)

This is the classic Weighted Interval Scheduling problem.

Step 1 — Store Jobs

We combine job information:

jobs = {start, end, profit}

Example:

[1,3,50]
[2,4,10]
[3,5,40]
[3,6,70]
Step 2 — Sort Jobs
sort(jobs.begin(), jobs.end());

Jobs are sorted by start time.

This helps us search the next compatible job.

Step 3 — DP Definition
dp[i] = maximum profit starting from job i
Step 4 — Base Case
if(i >= jobs.size())
    return 0

If no jobs remain, profit is 0.

Step 5 — Memoization
if(dp[i] != -1)
    return dp[i]

Avoids recomputing states.

Step 6 — Binary Search

We find the next job whose start ≥ current job end.

int l = i+1
int r = jobs.size()-1

Condition:

jobs[mid][0] >= end

If true → possible next job.

Step 7 — Two Choices

For every job we choose:

Take Job
take = jobs[i][2] + solve(next)

Meaning:

current job profit
+
profit of next compatible job
Skip Job
skip = solve(i+1)

Meaning:

ignore this job
move to next job
Step 8 — Take Maximum
dp[i] = max(take, skip)

We store the best result.

Code Structure
jobScheduling()
      ↓
create jobs vector
      ↓
sort jobs
      ↓
initialize dp
      ↓
solve(0)
Time Complexity
Sorting        → O(n log n)
DP states      → n
Binary search  → log n

Total:

O(n log n)
Space Complexity
O(n)

For:

dp array
recursion stack
Example
start  = [1,2,3,3]
end    = [3,4,5,6]
profit = [50,10,40,70]

Optimal schedule:

(1,3,50)
(3,6,70)

Total profit:

120
Pattern Learned

This problem teaches a very common DP pattern:

Sort intervals
+
Binary search next valid interval
+
DP (take / skip decision)

Used in problems like:

interval scheduling

maximum earnings problems

weighted interval DP