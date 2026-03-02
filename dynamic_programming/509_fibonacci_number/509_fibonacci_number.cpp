// Approach 1: Pure Recursion (Brute Force)

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


//2️⃣ Approach 2: Recursion + Memoization (Top-Down DP)

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

//Approach 3: Tabulation (Bottom-Up DP)

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

//Space Optimized Version (Best Version)

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