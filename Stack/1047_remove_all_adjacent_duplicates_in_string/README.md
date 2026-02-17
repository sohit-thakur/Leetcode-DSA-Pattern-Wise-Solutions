📌 Problem

Remove All Adjacent Duplicates in String
Platform: LeetCode

🧠 Approach
✔ Data Structure Used:

stack<char> (LIFO)

✔ Logic:

Traverse the string.

If stack is not empty and top equals current character → pop (remove duplicate).

Else → push character.

Build result from stack.

Reverse result (because stack gives reversed order).

⏱ Complexity Analysis

Time Complexity: O(n)

Each character is pushed and popped at most once.

Space Complexity: O(n)

Stack stores up to n characters.

💡 Key Insight

This is a classic stack pattern problem:

Whenever you see:

"Adjacent duplicates"

"Remove consecutive elements"

"Undo previous if condition matches"

→ Think Stack

🚀 Cleaner & More Optimal Version

Instead of using stack, we can use the string itself as a stack (more efficient).

class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        
        for(char c : s) {
            if(!result.empty() && result.back() == c)
                result.pop_back();
            else
                result.push_back(c);
        }
        
        return result;
    }
};

Why Better?

No extra reverse needed

Faster than stack

Same O(n) time

Cleaner code

🏆 Pattern Category

Stack

String manipulation

Simulation