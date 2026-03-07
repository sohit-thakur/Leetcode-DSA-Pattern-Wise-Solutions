Trapping Rain Water – Notes
Problem:

Goal: Find how much water is trapped between bars after raining.

Input: vector<int> height

Output: int total water trapped

Approach: Two-Pointer

Initialize pointers and max variables

l = 0, r = n-1
lMax = 0, rMax = 0
ans = 0

Move pointers until they meet (while(l < r)):

Update max heights seen so far

lMax = max(lMax, height[l])
rMax = max(rMax, height[r])

Compare left and right max

if(lMax < rMax) {
    ans += lMax - height[l]   // Water trapped at left
    l++
} else {
    ans += rMax - height[r]   // Water trapped at right
    r--
}

Return total water trapped

return ans
Complexity
Type	Complexity
Time	O(n)
Space	O(1)
Key Insight

Water trapped depends on the smaller of the two boundaries (left or right).

Two-pointer approach avoids extra arrays (leftMax and rightMax), making it space efficient.