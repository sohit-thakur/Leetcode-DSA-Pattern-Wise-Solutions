70. Climbing Stairs — DP Pattern Explanation
🔹 Problem Summary

You are climbing a staircase with n steps.

At each move, you can climb:

1 step

2 steps

Return the total number of distinct ways to reach the top.

🔹 Step 1: Identify the Pattern

This is a classic:

1D DP — Fibonacci Pattern

Why?

Because:

To reach step n, you must come from:

n-1  (1 step jump)
n-2  (2 step jump)

So:

ways[n] = ways[n-1] + ways[n-2]

That is exactly Fibonacci.

🔹 Step 2: Define State
dp[i] = number of ways to reach step i
🔹 Step 3: Base Cases
dp[0] = 1   (1 way: stay there)
dp[1] = 1   (only one way)
🔹 Step 4: Transition
dp[i] = dp[i-1] + dp[i-2]
🔹 Solution 1: Tabulation (Bottom-Up)
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;

        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
⏱ Time: O(n)
📦 Space: O(n)
🔹 Solution 2: Space Optimized (Best)

We only need last two values.

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;

        int prev2 = 1;  // dp[0]
        int prev1 = 1;  // dp[1]

        for(int i = 2; i <= n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
⏱ Time: O(n)
📦 Space: O(1)
🔹 Why This Is DP?

Because:

Same subproblems repeat.

Each state depends on previous states.

We build bigger answers from smaller ones.

🔹 Pattern Identification Trick

If problem says:

“How many ways to reach step n
and you can move 1 or 2 steps”

👉 Immediately think Fibonacci DP

🔥 Important Interview Insight

Climbing Stairs is:

Foundation of many advanced DP problems
(House Robber, Decode Ways, Coin Change variations)