📌 Problem

1239. Maximum Length of a Concatenated String with Unique Characters

💡 Approach: Recursion (Backtracking)
Core Idea

For every string at index i, we have two choices:

Exclude → skip current string

Include → only if adding it does NOT create duplicate characters

We explore all subsets and take the maximum valid length.

🔎 Duplicate Check Logic

Before including arr[i], we ensure:

No character in arr[i] already exists in temp

We use a frequency array of size 26 (since lowercase letters)

bool hasDuplicate(string &temp, string &s) {
    vector<int> freq(26, 0);

    for(char c : temp)
        freq[c - 'a']++;

    for(char c : s) {
        if(freq[c - 'a'] > 0)
            return true;
        freq[c - 'a']++;
    }

    return false;
}
🔁 Recursive Decision Tree
int solve(int i, vector<string>& arr, string temp, int n) {
    if(i >= n)
        return temp.size();

    // Exclude current string
    int exclude = solve(i + 1, arr, temp, n);

    int include = 0;

    // Include only if safe
    if(!hasDuplicate(temp, arr[i])) {
        include = solve(i + 1, arr, temp + arr[i], n);
    }

    return max(include, exclude);
}
🚀 Main Function
int maxLength(vector<string>& arr) {
    return solve(0, arr, "", arr.size());
}
⏱ Time Complexity

Worst case: O(2ⁿ × 26)

n ≤ 16 → feasible

📌 Key Learning Points

This is a subset generation problem

Pattern: Include / Exclude recursion

Good stepping stone before:

DP with memoization

Bitmask optimization (most efficient approach)