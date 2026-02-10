424. Longest Repeating Character Replacement

(Two Pointers + Sliding Window)

📌 Problem Statement

Given a string s and an integer k, you can replace at most k characters in any substring so that all characters in that substring are the same.

Return the length of the longest possible substring after replacements.

🧠 Key Insight

For any window [left … right]:

replacements needed = window size − frequency of most common character


The window is valid if:

(right - left + 1) - maxFreq ≤ k

💡 Approach Used

Two Pointers (left, right)

Sliding Window

Frequency Array of size 26 (uppercase letters)

Track:

maxFreq → highest frequency of a single character in current window

maxLen → maximum valid window length

🔁 Algorithm Steps

Initialize:

freq[26] to store character counts

left = 0, maxFreq = 0, maxLen = 0

Expand window using right

Update frequency and maxFreq

If replacements needed exceed k, shrink window from left

Update maxLen

Return maxLen

💻 C++ Code Implementation
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

🧪 Example Dry Run
Input
s = "AABABBA", k = 1

Explanation

"AABA" → replace one B → valid → length = 4

Longer windows need more than 1 replacement → invalid

Output
4

⏱️ Complexity Analysis
Metric	Complexity
Time	O(n)
Space	O(1)

(Only 26 uppercase letters are stored)

🧩 Pattern Used

Sliding Window

Two Pointers

Frequency Counting

❗ Important Note

We do not decrease maxFreq when shrinking the window.
This optimization keeps the algorithm linear and does not affect correctness.

🎯 Interview Takeaway

Maintain a sliding window and ensure the number of replacements required does not exceed k by tracking the most frequent character.