746. Min Cost Climbing Stairs
🔹 Problem Summary

You are given an array cost.

cost[i] = cost of stepping on stair i

You can climb either 1 step or 2 steps

You can start from index 0 or 1

You want to reach top (after last index) with minimum cost

🔹 Step 1: Understand the Pattern

This is Fibonacci-style DP, but instead of counting ways,
we are minimizing cost.

To reach step i, you must come from:

i-1  (1 step jump)
i-2  (2 step jump)

So:

dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
🔹 Step 2: Define State
dp[i] = minimum cost to reach step i
🔹 Step 3: Base Cases
dp[0] = cost[0]
dp[1] = cost[1]
🔹 Step 4: Final Answer

We don’t need to land on last step.

To reach the top:

min(dp[n-1], dp[n-2])
🔹 Solution 1 — Tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }

        return min(dp[n-1], dp[n-2]);
    }
};
⏱ Time: O(n)
📦 Space: O(n)
🔹 Solution 2 — Space Optimized (Best)

We only need last two values.

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2; i < n; i++){
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
⏱ Time: O(n)
📦 Space: O(1)
🔹 Why This Is DP?

Because:

Problem breaks into smaller subproblems.

Optimal answer depends on previous optimal answers.

Same states would repeat without storing.

🔥 Pattern Recognition Trick

If you see:

“1 step or 2 steps”

“Minimize or count ways”

👉 Think Fibonacci-style DP