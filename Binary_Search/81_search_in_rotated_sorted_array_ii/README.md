Since you are actively using GitHub (username: thakursohit) and frequently contribute to DSA repositories, these notes are formatted specifically for a Markdown (.md) file. This is perfect for your personal "LeetCode-Solutions" repo.📂 Git-Ready Notes: Search in Rotated Sorted Array II (LC 81)📌 Problem DescriptionGiven an integer array nums sorted in ascending order (with duplicates) that has been rotated at an unknown pivot, return true if target is in nums, or false otherwise.💡 Key Insight: The Duplicate DilemmaWhen duplicates exist, we can hit a scenario where nums[left] == nums[mid] == nums[right].Example: [1, 0, 1, 1, 1]Here, binary search cannot determine which side is sorted because both ends look identical to the middle.Fix: Manually shrink the search space by incrementing the left pointer and decrementing the right pointer until the "blind spot" is removed.💻 Optimized C++ ImplementationC++class Solution {
public:
    /**
     * Time Complexity: O(log N) average, O(N) worst case (all duplicates)
     * Space Complexity: O(1)
     */
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;

        while(i <= j) {
            int mid = i + (j - i) / 2;

            if(nums[mid] == target) return true;

            // 1. Handle the Duplicate Edge Case
            if(nums[i] == nums[mid] && nums[mid] == nums[j]) {
                i++;
                j--;
                continue; // Skip further logic and recalculate mid
            }

            // 2. Determine which half is sorted
            if(nums[mid] >= nums[i]) { 
                // Left side is sorted
                if(target >= nums[i] && target < nums[mid]) {
                    j = mid - 1; // Target is in the sorted range
                } else {
                    i = mid + 1; // Search the right side
                }
            } else { 
                // Right side is sorted
                if(target > nums[mid] && target <= nums[j]) {
                    i = mid + 1; // Target is in the sorted range
                } else {
                    j = mid - 1; // Search the left side
                }
            }
        }
        return false;
    }
};
🛠 Git Commit StrategyIf you are adding this to your repository, here is a suggested commit message following best practices:git commit -m "feat: add LeetCode 81 Search in Rotated Sorted Array II with duplicate handling"🚀 Summary for PlacementsDistinct Elements: Always $O(\log n)$.With Duplicates: Average $O(\log n)$, but Worst $O(n)$.Interview Tip: If the interviewer asks why it's $O(n)$, use the example [1, 1, 1, 1, 0, 1, 1]. Explain that since we can't discard half the array when nums[i] == nums[mid] == nums[j], we are forced to check elements one by one.