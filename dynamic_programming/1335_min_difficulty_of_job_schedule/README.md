This is now a correct recursion + memoization solution using a fixed-size array (t[301][11]) — exactly what you wanted.

Key Points:

Base case:

if(days == 1)

Forces all remaining jobs into the last day.

Returns the max of remaining jobs.

Memoization:

if(t[idx][days] != -1) return t[idx][days];

Reuses previously computed answers.

Saves time by preventing repeated recursion.

Loop:

for(int i = idx; i <= n - days; i++)

Chooses how many jobs today will take.

Ensures at least one job per remaining day.

Answer storage:

return t[idx][days] = ans;

Saves the computed minimum for the current (idx, days) state.