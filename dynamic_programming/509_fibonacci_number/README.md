📘 Fibonacci Using Recursion, Memoization & Tabulation (DP)

This file demonstrates three approaches to solving the Fibonacci problem:

F(n) = F(n-1) + F(n-2)

Base cases:

F(0) = 0
F(1) = 1
1️⃣ Approach 1: Pure Recursion (Brute Force)
🔹 Code
class Solution {
public:
    int rec(int n){
        if(n==0 || n==1) return n;
        return rec(n-1) + rec(n-2);
    }

    int fib(int n) {
        return rec(n);
    }
};
🔹 Explanation

Direct implementation of Fibonacci formula.

Breaks the problem into smaller subproblems.

Does NOT store results.

Recomputes same values multiple times.

🔹 Time Complexity
O(2^n)

Why?
Because it forms a recursion tree where each call branches into 2 calls.

🔹 Space Complexity
O(n)

Due to recursion stack depth.

❌ Problem

Huge overlapping subproblems → very slow for large n.

2️⃣ Approach 2: Recursion + Memoization (Top-Down DP)
🔹 Code
class Solution {
public:
    int rec(int n, vector<int>& dp){
        if(n==0 || n==1) return n;

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = rec(n-1, dp) + rec(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+1, -1);
        return rec(n, dp);
    }
};
🔹 Explanation

Same recursion logic.

But we store already computed values in dp.

Before computing, we check if result exists.

This avoids recomputation.

🔹 Why This Works?

Instead of solving:

F(3) again and again

We compute it once and reuse it.

🔹 Time Complexity
O(n)

Each state computed once.

🔹 Space Complexity
O(n)

Recursion stack

DP array

✅ Advantage

Much faster than pure recursion.

3️⃣ Approach 3: Tabulation (Bottom-Up DP)
🔹 Code
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;

        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
🔹 Explanation

No recursion.

Start from base cases.

Build answers step by step.

Instead of breaking downward:

F(5) → F(4) → F(3)

We build upward:

F(0), F(1), F(2), F(3) ...
🔹 Time Complexity
O(n)
🔹 Space Complexity
O(n)
4️⃣ Space Optimized Version (Best Version)

We only need last 2 values.

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;

        int prev2 = 0;
        int prev1 = 1;

        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
🔹 Time Complexity
O(n)
🔹 Space Complexity
O(1)

Most optimal solution.

📊 Comparison Table
Approach	Time	Space	Recommended
Recursion	O(2^n)	O(n)	❌ No
Memoization	O(n)	O(n)	✅ Yes
Tabulation	O(n)	O(n)	✅ Yes
Space Optimized	O(n)	O(1)	⭐ Best
🧠 DP Learning Insight

Fibonacci teaches the core DP concept:

Define state

Identify recurrence

Add memoization OR build bottom-up

If you understand Fibonacci properly,
you understand 40% of DP foundation.