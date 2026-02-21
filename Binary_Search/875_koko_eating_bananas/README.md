📝 Koko Eating Bananas — Notes
🔹 Problem Type

Binary Search on Answer

🔹 Key Idea

We are not searching in the array.
We are searching for the minimum valid speed k.

If a speed works → any bigger speed will also work.
If a speed fails → any smaller speed will also fail.

This monotonic behavior ⇒ use binary search.

🔹 Search Space
left = 1
right = max(piles)

Minimum speed = 1 banana/hour

Maximum speed = largest pile

🔹 Core Logic
Calculate required hours for speed mid
hours += (pile + mid - 1) / mid;

Why this works?

⌈
𝑝
𝑖
𝑙
𝑒
𝑚
𝑖
𝑑
⌉
⌈
mid
pile
	​

⌉

This is the ceil division trick (very important for interviews).

🔹 Binary Search Logic
while (left < right)
Case 1: hours <= h

Speed is valid
Try smaller speed

right = mid;
Case 2: hours > h

Speed too slow
Increase speed

left = mid + 1;
🔹 Why long long hours?

Because:

piles[i] can be large (up to 10⁹)

total hours can overflow int

Always use:

long long hours = 0;
🔹 Time Complexity
𝑂
(
𝑛
log
⁡
𝑚
)
O(nlogm)

n = number of piles

m = maximum pile value

🔹 Important Interview Pattern

This pattern also appears in:

Allocate Minimum Pages

Capacity to Ship Packages

Aggressive Cows

Minimum Days to Make Bouquets

🔹 Final Code Structure (Conceptual Flow)

Define search space

Binary search

Check feasibility

Adjust search range

Return answer