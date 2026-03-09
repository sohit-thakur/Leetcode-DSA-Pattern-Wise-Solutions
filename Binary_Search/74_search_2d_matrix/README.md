Problem Idea

You are given a 2D matrix where:

Each row is sorted in ascending order.

The first element of each row is greater than the last element of the previous row.

Goal: Return true if target exists, otherwise false.

2. Approach Used in Your Code

Your approach has two steps:

Step 1: Find the Possible Row

You check:

if(matrix[i][m-1] >= target)

Meaning:

matrix[i][m-1] → last element of row i

If last element ≥ target → target can exist in this row

Example:

Matrix

1  3  5  7
10 11 16 20
23 30 34 60

Target = 16

Check rows:

Row	Last Element	Condition
0	7	7 < 16 ❌
1	20	20 ≥ 16 ✅ (search here)
Step 2: Apply Binary Search in That Row
low = 0
high = m-1

Binary search logic:

mid = low + (high - low) / 2

Conditions:

Condition	Action
matrix[i][mid] == target	return true
matrix[i][mid] > target	high = mid - 1
matrix[i][mid] < target	low = mid + 1
3. Dry Run

Matrix

1  3  5  7
10 11 16 20
23 30 34 60

Target = 16

Row Selection
Row0 → last = 7  < 16 → skip
Row1 → last = 20 ≥ 16 → search here
Binary Search

Row1 → [10,11,16,20]

low = 0
high = 3

mid = 1 → 11 < 16 → low = 2
mid = 2 → 16 == target → return true
4. Time Complexity

Row scan:

O(n)

Binary search:

O(log m)

Total:

O(n log m)

Where

n = number of rows

m = number of columns

5. Space Complexity
O(1)

No extra space used.

6. Optimization (Better Approach)

Since matrix behaves like a sorted 1D array, we can apply single binary search.

Time complexity becomes:

O(log(n*m))
7. Important Observation

Your condition:

if(matrix[i][m-1] >= target)

works because rows are sorted and non-overlapping.

8. Small Optimization in Your Code

After searching the row, you can break because target cannot appear in next rows.

Example improvement:

if(matrix[i][m-1] >= target){
    // binary search
    return false;
}