Below are clean, interview-ready Git notes you can directly put in your GitHub repository for LeetCode 560 – Subarray Sum Equals K.

📌 Subarray Sum Equals K (LeetCode 560)
🔹 Problem Statement

Given an integer array nums and an integer k, return the total number of continuous subarrays whose sum equals k.

🔹 Approach: Prefix Sum + Hash Map
Key Insight

If:

prefixSum[j] - prefixSum[i] = k


Then the subarray (i+1 → j) has sum k.

Rewriting:

prefixSum[i] = prefixSum[j] - k


So for every prefix sum, we check how many times (prefixSum - k) has appeared before.

🔹 Algorithm Steps

Initialize a hash map to store prefix sum frequencies

Store freq[0] = 1 (base case for subarrays starting at index 0)

Traverse the array

Update running prefix sum

If (prefixSum - k) exists in the map, add its frequency to the count

Store/update current prefix sum in the map

🔹 C++ Implementation
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            if (freq.find(prefixSum - k) != freq.end()) {
                count += freq[prefixSum - k];
            }

            freq[prefixSum]++;
        }
        return count;
    }
};

🔹 Dry Run Example
nums = [1, 2, 3], k = 3

Index	Prefix Sum	prefixSum - k	Count
0	1	-2	0
1	3	0	+1
2	6	3	+1

✅ Answer = 2

🔹 Why Not Sliding Window?

Sliding window works only when all numbers are positive

Negative numbers break window logic

Subarrays can be of variable length

🔹 Complexity Analysis

Time Complexity: O(n)

Space Complexity: O(n)

🔹 Interview Tip

This is a classic prefix sum + hashmap counting problem. Always initialize freq[0] = 1 to handle subarrays starting from index 0.