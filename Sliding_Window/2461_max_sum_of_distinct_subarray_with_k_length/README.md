🟢 Problem Summary

Given:

Integer array nums

Integer k

Return:

Maximum sum of any subarray of length k

All elements inside the subarray must be distinct

If no valid subarray exists → return 0.

🟢 Approach
🔹 Technique Used

Sliding Window

Hash Map (unordered_map) for frequency tracking

🔹 Key Idea

Maintain:

Window size exactly k

Track frequency of elements inside window

If freq.size() == k, then all elements are distinct

🟢 Algorithm

Initialize:

sum = 0

maxSum = 0

left = 0

unordered_map<int,int> freq

Expand window using right pointer:

Add element to sum

Increase frequency

If window size > k:

Remove left element from sum

Decrease frequency

Erase if frequency becomes 0

Move left++

If window size == k and freq.size() == k:

Update maxSum

🟢 Code
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        if(n < k) return 0;

        unordered_map<int,int> freq;
        long long sum = 0;
        long long maxSum = 0;

        int left = 0;

        for(int right = 0; right < n; right++) {

            sum += nums[right];
            freq[nums[right]]++;

            if(right - left + 1 > k) {
                sum -= nums[left];
                freq[nums[left]]--;

                if(freq[nums[left]] == 0)
                    freq.erase(nums[left]);

                left++;
            }

            if(right - left + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

🟢 Complexity Analysis

Time Complexity: O(n)
Each element enters and leaves window once.

Space Complexity: O(k)
At most k distinct elements stored in map.

🟢 Important Observations

freq.size() == k ⇒ All elements are unique.

Always shrink window if size exceeds k.

Use long long to avoid overflow.

🟢 Common Mistakes

❌ Using set without careful shrinking
❌ Forgetting to erase element when frequency becomes 0
❌ Using int instead of long long
❌ Updating answer when window size < k