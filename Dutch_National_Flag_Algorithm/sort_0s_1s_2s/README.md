🟢 Sort 0s, 1s, and 2s (Dutch National Flag Problem)
📌 Problem Statement

Given an array arr containing only 0s, 1s, and 2s, sort the array in-place so that:

all 0s appear first, then all 1s, then all 2s


Constraints:

Must be done in one pass.

Must use constant space.

Do not use any built-in sort functions.

💡 Approach: Three Pointers / Dutch National Flag

We use three pointers:

low → next position for 0

mid → current element under consideration

high → next position for 2

Algorithm:

While mid <= high:

If arr[mid] == 0 → swap with arr[low], increment low and mid.

If arr[mid] == 1 → just move mid++.

If arr[mid] == 2 → swap with arr[high], decrement high (don’t increment mid).

Idea:

0s move to the left (low)

1s stay in the middle (mid)

2s move to the right (high)

This sorts the array in one pass.

🧪 Example

Input:

arr = [2, 0, 2, 1, 1, 0]


Output:

[0, 0, 1, 1, 2, 2]

✅ C++ Implementation
class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0;
        int high = arr.size() - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else { 
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

⏱ Complexity Analysis
Metric	Complexity
Time	O(n)
Space	O(1)

✅ One pass, in-place sorting using constant space.

🎯 Key Insight

By using three pointers, we efficiently partition the array into three regions:

[0..low-1] → all 0s

[low..mid-1] → all 1s

[high+1..n-1] → all 2s
This is the optimal Dutch National Flag approach.