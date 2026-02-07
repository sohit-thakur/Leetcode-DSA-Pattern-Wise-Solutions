977. Squares of a Sorted Array
🔹 Problem

Given a sorted array nums, return a new array containing the squares of each element, also sorted.

🔹 Approach

Two Pointers

Initialize two pointers at the start and end of the array

Compare absolute values from both ends

Place the larger square at the end of the result array

Move pointers accordingly

🔹 C++ Solution
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, k = nums.size() - 1;
        vector<int> result(nums.size());

        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                result[k--] = nums[i] * nums[i];
                i++;
            } else {
                result[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return result;
    }
};
