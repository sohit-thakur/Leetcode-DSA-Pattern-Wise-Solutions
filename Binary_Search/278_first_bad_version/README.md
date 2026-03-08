Problem Context

You need to find the first bad version among n versions.

API isBadVersion(version) tells whether a version is bad.

All versions after a bad version are also bad.

Code Breakdown with Notes
int i = 1, j = n; // Search range: versions from 1 to n (inclusive)

i → start of range

j → end of range

while(i <= j) {

Loop runs while the range is valid (inclusive).

Stops when i > j.

    int mid = i + (j - i) / 2;

Calculates middle index safely.

Avoids overflow compared to (i + j) / 2.

    if(isBadVersion(mid)){
        j = mid - 1;
    }

If mid is bad, the first bad version could be mid or earlier.

Narrow search to left half.

    else {
        i = mid + 1;
    }

If mid is good, the first bad version must be after mid.

Narrow search to right half.

return i;

After the loop ends:

i is the smallest index where isBadVersion(i) is true.

Correctly returns the first bad version.

Key Points / Takeaways

Binary Search Template: This is a lower-bound binary search pattern.

Loop Condition: i <= j ensures all elements are considered.

Return Value: Returning i works because the loop guarantees i stops at the first bad version.

Overflow Safety: mid = i + (j-i)/2 prevents integer overflow for large n.

Example Trace

n = 5, first bad version = 4:

i	j	mid	isBadVersion(mid)	Action
1	5	3	false	i = mid+1=4
4	5	4	true	j = mid-1=3

Loop ends → i = 4 → correct first bad version.

This code is efficient (O(log n) time) and minimal API calls, which is exactly what LeetCode expects.