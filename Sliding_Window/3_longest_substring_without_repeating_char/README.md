Longest Substring Without Repeating Characters

(Two Pointers + Sliding Window)

📌 Problem Statement

Given a string s, find the length of the longest substring without repeating characters.

🧠 Approach Used

Two Pointer + Sliding Window + Hash Set

💡 Core Idea

Maintain a sliding window with two pointers:

left → start of window

right → end of window

Use a hash set to ensure all characters in the window are unique

Expand the window by moving right

Shrink the window from left when a duplicate character appears

🔁 Algorithm Steps

Initialize:

unordered_set<char> st → stores unique characters

left = 0

maxCount = 0

Traverse the string using right

If s[right] already exists in the set:

Remove characters from left until duplicate is removed

Insert s[right] into the set

Update the maximum window size

Return maxCount

💻 Code Implementation (C++)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0;
        int maxCount = 0;

        for(int right = 0; right < s.size(); right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxCount = max(maxCount, right - left + 1);
        }
        return maxCount;
    }
};

🧪 Example Dry Run
Input
s = "abcabcbb"

Window Movement
"abc" → length 3
Window shifts on duplicate characters

Output
3

⏱️ Complexity Analysis
Metric	Complexity
Time	O(n)
Space	O(n)

Each character is added and removed from the set at most once.

🧩 Pattern Used

Sliding Window

Two Pointers

Hashing (unordered_set)

🎯 Key Takeaway

The sliding window always maintains a substring with unique characters, ensuring optimal traversal in linear time.

📌 Interview Tip

This approach is optimal and commonly expected

Can be further optimized using an array or hash map for last seen indices