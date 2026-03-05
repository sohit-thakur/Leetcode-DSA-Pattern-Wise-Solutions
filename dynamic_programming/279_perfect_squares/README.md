Problem

Given an integer n, return the minimum number of perfect square numbers whose sum equals n.

Example:

n = 12
12 = 4 + 4 + 4
Answer = 3
n = 13
13 = 4 + 9
Answer = 2
Approach
Recursion + Memoization (Top-Down DP)

Idea:

For every number n, try subtracting every perfect square ≤ n and recursively solve the remaining value.

Store already computed results in a memoization array to avoid recomputation.

Code
class Solution {
public:
    int arr[10001];

    int helper(int n){
        if(n==0) return 0;

        if(arr[n] != -1)
            return arr[n];

        int minCount = INT_MAX;

        for(int i=1; i*i<=n; i++){
            int result = 1 + helper(n - i*i);
            minCount = min(minCount, result);
        }

        return arr[n] = minCount;
    }

    int numSquares(int n) {
        memset(arr, -1, sizeof(arr));
        return helper(n);
    }
};
Key Concepts
1. Base Case
if(n == 0) return 0

If the remaining number becomes 0, no squares are needed.

2. Memoization
if(arr[n] != -1)
    return arr[n]

If the answer for n was already calculated, return it directly.

This prevents repeated recursion.

3. Recurrence Relation
helper(n) = 1 + helper(n - i*i)

Meaning:

take one perfect square
+
solve remaining number

Example for n = 12

12 = 1 + helper(11)
12 = 4 + helper(8)
12 = 9 + helper(3)

Take the minimum result.

4. Tracking Minimum
minCount = min(minCount, result)

Start with:

minCount = INT_MAX

Then update it with the smallest value.

5. Storing Result
arr[n] = minCount

This stores the computed value for reuse.

Why memset is used
memset(arr, -1, sizeof(arr))

Purpose:

Initialize the memo array with -1.

Meaning:

-1 → value not computed yet
Time Complexity
O(n * √n)

Because:

n states

each state checks up to √n squares.

Space Complexity
O(n)

For memoization array + recursion stack.

Example Flow (n = 12)
helper(12)
  → helper(11)
  → helper(8)
  → helper(3)

Eventually memo table becomes:

arr[1] = 1
arr[2] = 2
arr[3] = 3
arr[4] = 1
arr[8] = 2
arr[12] = 3

Final result:

3

✅ Pattern learned

This problem teaches a common DP pattern:

Minimize something
+
Try all possible choices
+
Memoization