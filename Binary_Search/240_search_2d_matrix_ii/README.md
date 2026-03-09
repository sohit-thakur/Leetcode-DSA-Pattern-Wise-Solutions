Search in 2D Matrix – Staircase Search (Notes)
1. Matrix Property

This approach works when:

Each row is sorted (left → right increasing)

Each column is sorted (top → bottom increasing)

Example matrix:

1   4   7   11
2   5   8   12
3   6   9   16
10 13  14  17
2. Idea of the Algorithm

We start from the top-right corner.

Initial position:

i = 0
j = m - 1

Why top-right?

Because:

Left side → smaller values

Down side → larger values

So we can eliminate one row or one column each step.

3. Algorithm Steps

Start at top-right element.

Compare with target.

Case 1
matrix[i][j] == target

Return true.

Case 2
matrix[i][j] > target

Move left

j--

Reason:
Everything below is even larger, so target cannot be there.

Case 3
matrix[i][j] < target

Move down

i++

Reason:
Everything left is smaller, so target cannot be there.

4. Code Flow
int i = 0;
int j = m - 1;

while(i < n && j >= 0)

Loop runs until:

row index exceeds matrix

column index becomes negative

5. Dry Run Example

Matrix

1 4 7
2 5 8
3 6 9

Target = 5

Start:

i=0 j=2 → 7
7 > 5 → move left
j=1
i=0 j=1 → 4
4 < 5 → move down
i=1
i=1 j=1 → 5
Found

Return true.

6. Time Complexity

Worst case we move:

at most n rows

at most m columns

Time Complexity = O(n + m)
7. Space Complexity
O(1)

No extra memory used.

8. Why It Is Called Staircase Search

The movement pattern looks like a staircase path in the matrix:

        ↓
1   4   7
    ↓
2   5   8
9. Key Interview Insight

Comparison of approaches:

Approach	Time Complexity
Row wise binary search	O(n log m)
Staircase search	O(n + m)
Flatten + binary search	O(log(n*m))