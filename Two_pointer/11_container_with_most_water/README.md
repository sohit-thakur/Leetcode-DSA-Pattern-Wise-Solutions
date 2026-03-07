11. Container With Most Water
Problem

Given an array height[], where each element represents the height of a vertical line.

Find two lines that together with the x-axis form a container that holds the maximum amount of water.

Example
Input:  height = [1,8,6,2,5,4,8,3,7]
Output: 49
Key Idea

Water stored depends on:

area = min(height[i], height[j]) * (j - i)

Where:

height → smaller wall
width  → distance between walls
Approach — Two Pointer

Use two pointers:

i → start
j → end

At every step:

Calculate area

Update maximum area

Move the pointer with smaller height

Reason:

Area depends on smaller wall

Moving the taller wall cannot increase area.

Algorithm

Initialize:

i = 0
j = n - 1
maxArea = 0

While i < j

Compute area:

min(height[i], height[j]) * (j - i)

Update maximum area.

Move pointer:

if height[i] < height[j]
    i++
else
    j--
Code
class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size() - 1;
        int area = 0;

        while(i < j){

            int MinLen = min(height[i], height[j]);
            int breadth = j - i;

            int curr = MinLen * breadth;

            area = max(area, curr);

            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return area;
    }
};
Complexity
Time Complexity
O(n)
Space Complexity
O(1)
Why Move Smaller Height?

Example

height[i] = 5
height[j] = 10

Water level depends on 5.

Moving j will not increase min height, but reduces width.

So we move:

i++
Pattern Learned
Two Pointer (Opposite Direction)

Key rule:

move the pointer with smaller value
Similar Problems

Practice next:

Two Sum II – Input Array Is Sorted

3Sum

Trapping Rain Water