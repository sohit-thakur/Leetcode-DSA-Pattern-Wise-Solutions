Valid Palindrome II — Notes
Problem

Given a string s, return true if it can become a palindrome after deleting at most one character.

Example

Input:  s = "abca"
Output: true
Explanation: Remove 'b' or 'c'
Approach — Two Pointer

Use two pointers:

i → start
j → end

Compare characters from both sides.

Algorithm

Start pointers:

i = 0
j = n-1

If characters match:

i++
j--

If mismatch occurs:

We are allowed one deletion, so check two possibilities.

skip left  → check(i+1 , j)
skip right → check(i , j-1)

If any substring is palindrome → return true.

Helper Function

isPal() checks if substring is palindrome.

bool isPal(const string& s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
Full Code
class Solution {
public:

    bool isPal(const string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {

        int i = 0;
        int j = s.length() - 1;

        while(i < j){

            if(s[i] != s[j]){
                return isPal(s,i+1,j) || isPal(s,i,j-1);
            }

            i++;
            j--;
        }

        return true;
    }
};
Why const string& s
const string& s

Benefits:

Avoids copying the string

Faster

Prevents modification

Complexity

Time Complexity

O(n)

Space Complexity

O(1)
Key Pattern Learned
Two Pointer + One Modification

When mismatch occurs:

check(i+1 , j)
check(i , j-1)
Similar Problems

Practice next:

Valid Palindrome

Palindrome Linked List

Longest Palindromic Substring

✅ DSA Insight:
Problems that say:

remove one element
delete one character
at most one modification

often use two pointers + checking two cases.