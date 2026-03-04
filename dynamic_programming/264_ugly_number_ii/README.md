📌 264. Ugly Number II

Platform: LeetCode

🧠 Problem Summary

Find the nth ugly number.

Ugly numbers:

Positive numbers

Prime factors only include 2, 3, 5

1 is considered ugly

🚀 Approach: DP + 3 Pointers (Optimal)
💡 Core Idea

Every ugly number can be generated from:

Previous ugly × 2

Previous ugly × 3

Previous ugly × 5

Instead of checking every number,
we build the sequence in sorted order.

🏗️ Construction Logic

We maintain:

i2 → pointer for multiples of 2

i3 → pointer for multiples of 3

i5 → pointer for multiples of 5

At every step:

nextUgly = min(
    dp[i2] * 2,
    dp[i3] * 3,
    dp[i5] * 5
)

Then increment the pointer(s) that produced it.

💻 Code
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;

        for(int i = 1; i < n; i++) {
            long i2ugly = dp[i2] * 2;
            long i3ugly = dp[i3] * 3;
            long i5ugly = dp[i5] * 5;

            dp[i] = min({i2ugly, i3ugly, i5ugly});

            if(dp[i] == i2ugly) i2++;
            if(dp[i] == i3ugly) i3++;
            if(dp[i] == i5ugly) i5++;
        }

        return dp[n - 1];
    }
};
🔎 Why We Use 3 Separate if Statements (Not else if)

Example:

6 = 2 × 3
6 = 3 × 2

If we used else if, duplicates would occur.

Using separate if ensures:

All matching pointers advance

No duplicate ugly numbers

📈 Time & Space Complexity

Time: O(n)

Space: O(n)

Much better than brute force (which is ~O(n log n)).

🎯 Pattern Recognition

This problem teaches:

Multi-pointer DP

Merging sorted streams

Sequence generation without checking every number

🔥 Advanced Connection

This pattern directly extends to:

Super Ugly Number (k primes)

K-way merge problems

Generating sorted sequences efficiently