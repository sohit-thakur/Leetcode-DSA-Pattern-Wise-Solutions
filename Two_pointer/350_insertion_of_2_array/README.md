🔹 LeetCode 350 — Intersection of Two Arrays II
✅ Approach 1: Hash Map (Frequency Count)
💡 Idea

Count frequency of each element in one array

Traverse the second array

If element exists in the map with count > 0:

Add it to the answer

Decrease its frequency

🧠 Why it works

Each element is added only as many times as it appears in both arrays

Frequency map prevents over-counting duplicates

⏱️ Complexity

Time: O(n + m)

Space: O(min(n, m))

🟢 When to use

Arrays are unsorted

Want faster execution

Extra space is allowed

⚠️ Drawback

Uses extra memory

✅ Approach 2: Two Pointers (Sorting)
💡 Idea

Sort both arrays

Use two pointers to compare elements

If equal → add to answer and move both pointers

If not equal → move pointer pointing to smaller element

🧠 Why it works

Sorting aligns equal elements

Two pointers ensure linear scan

Naturally handles duplicates

⏱️ Complexity

Time: O(n log n + m log m)

Space: O(1) (excluding output)

🟢 When to use

Arrays are already sorted

Space optimization is required

Interviewer prefers two-pointer technique

⚠️ Drawback

Sorting increases time complexity

📊 Comparison Summary
Feature	Hash Map	Two Pointers
Sorting required	❌ No	✅ Yes
Time Complexity	O(n + m)	O(n log n)
Extra Space	O(n)	O(1)
Handles duplicates	✅ Yes	✅ Yes
Best for	Speed	Space
🎯 Interview Tip

Use Hash Map for optimal time.
Use Two Pointers when arrays are sorted or space is constrained.