Problem Context

You are playing a number guessing game between 1 and n.

The API guess(num) tells you:

Return Value	Meaning
0	You guessed correctly
-1	Your guess is higher than the target
1	Your guess is lower than the target

Goal: find the correct number using binary search.

Code Breakdown
int i = 1, j = n;

i → start of the search range

j → end of the search range

while(i <= j){
    int mid = i + (j - i) / 2;  // safe mid calculation

Binary search continues as long as the range is valid

mid = i + (j-i)/2 avoids integer overflow

    if(guess(mid) == 0){
        return mid;  // found the number
    }

If API returns 0 → mid is the correct number → return immediately

    else if(guess(mid) == -1){
        j = mid - 1;  // guess is higher than target → move left
    }

API says guess is too high → target is smaller

Narrow search left, so j = mid - 1

    else{
        i = mid + 1;  // guess is lower than target → move right
    }

API says guess is too low → target is bigger

Narrow search right, so i = mid + 1

return -1;

Safety return → should never reach here because the correct number exists in [1, n]

How It Works

Binary search principle:

Reduce search space by half each step using mid

Move left if the guess is too high

Move right if the guess is too low

Loop ends when i > j → correct number is already returned

Example Trace

Suppose n = 10, target = 6:

i	j	mid	guess(mid)	Action
1	10	5	1	i = mid+1 = 6
6	10	8	-1	j = mid-1 = 7
6	7	6	0	return 6

Number found in 3 guesses, efficient (O(log n) calls).

Key Notes

Loop condition i <= j ensures all numbers in the inclusive range are considered.

mid = i + (j-i)/2 avoids overflow for large n.

API call logic:

-1 → move left (j = mid - 1)

1 → move right (i = mid + 1)

Time Complexity: O(log n)

Space Complexity: O(1)