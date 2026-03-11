Notes – Maximum Number of Vowels in a Substring (Sliding Window)
1. Problem Idea

Given:

String s

Integer k

Find the maximum number of vowels in any substring of length k.

Vowels:

a, e, i, o, u

2. Approach – Sliding Window

Instead of checking every substring again and again:

Count vowels in the first window of size k.

Slide the window one step to the right.

Add the new character.

Remove the leftmost character.

Track the maximum vowel count.

3. Algorithm Steps
Step 1 — Helper Function

Check whether a character is a vowel.

bool isVowel(char c){
    return c =='a' || c =='e' || c =='i' || c =='o' || c =='u';
}

Step 2 — First Window

Count vowels in the first k characters.

for(int i=0;i<k;i++){
    if(isVowel(s[i])){
        count++;
    }
}


Store the result:

maxCount = count;

Step 3 — Slide the Window

Move window from k to n-1.

for(int j=k;j<n;j++){


Add the new right element.

if(isVowel(s[j])){
    count++;
}


Remove the left element leaving the window.

if(isVowel(s[j-k])){
    count--;
}


Update maximum.

maxCount = max(maxCount,count);

4. Dry Run Example
s = "abciiidef"
k = 3


Windows:

abc → 1 vowel
bci → 1 vowel
cii → 2 vowels
iii → 3 vowels
iid → 2 vowels


Maximum = 3

5. Time Complexity
O(n)


Each character is processed once.

6. Space Complexity
O(1)


Only integer variables used.

7. Important Sliding Window Pattern

General pattern:

for(int i=0;i<k;i++) {
    // build first window
}

for(int j=k;j<n;j++) {
    // add right element
    // remove left element
    // update answer
}

8. Key Interview Insight

This problem teaches the fixed-size sliding window technique, which is used in many problems like:

Maximum Sum Subarray of Size K

Maximum Average Subarray

Permutation in String

Find All Anagrams in a String