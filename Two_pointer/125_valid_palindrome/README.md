Valid Palindrome – Notes
Problem

Given a string s, determine if it is a palindrome after:

converting all letters to lowercase

removing non-alphanumeric characters

Example

Input: "A man, a plan, a canal: Panama"
Output: true
Approach 1 — Extra String (Brute Force)
Idea

Traverse string.

Keep only alphanumeric characters.

Convert them to lowercase.

Create:

temp → forward string

temp1 → reverse string

Compare both.

Code
class Solution {
public:
    bool isPalindrome(string s) {
        string temp, temp1;

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                temp += tolower(s[i]);
            }
        }

        for(int i = s.size()-1; i >= 0; i--){
            if(isalnum(s[i])){
                temp1 += tolower(s[i]);
            }
        }

        return temp == temp1;
    }
};
Complexity

Time Complexity

O(n)

Space Complexity

O(n)

(extra strings used)

Approach 2 — Two Pointer (Optimal)
Idea

Use two pointers.

i → start

j → end

Steps:

Skip non-alphanumeric characters.

Compare lowercase characters.

Move pointers inward.

Code
class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0;
        int j = s.length() - 1;

        while(i < j){

            if(!isalnum(s[i])){
                i++;
            }
            else if(!isalnum(s[j])){
                j--;
            }
            else{
                if(tolower(s[i]) != tolower(s[j])){
                    return false;
                }
                i++;
                j--;
            }
        }

        return true;
    }
};
Complexity (Optimal Solution)

Time Complexity

O(n)

Space Complexity

O(1)

No extra string used.

Key Functions Used
Function	Purpose
isalnum()	Checks if character is letter or digit
tolower()	Converts character to lowercase
Why Two Pointer is Better
Method	Space	Efficiency
Extra string	O(n)	slower
Two pointer	O(1)	optimal
Pattern Learned

This problem teaches Two Pointer Pattern:

Left pointer → start
Right pointer → end
Compare and move inward

This pattern is used in many problems like:

Two Sum II – Input Array Is Sorted

Container With Most Water

3Sum

✅ Tip for interviews:
Whenever the problem involves:

palindrome

sorted arrays

comparing both ends

Think Two Pointer first.