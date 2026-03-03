class Solution {
public:
    int t[301][11];
    int solve(vector<int>& job, int idx, int n, int days) {
        if(days == 1) {
            int mx = 0;
            for(int i = idx; i < n; i++)
                mx = max(mx, job[i]);
            return mx;
        }
        if(t[idx][days] != -1)
            return t[idx][days];

        int mx = 0;
        int ans = INT_MAX;
        for(int i = idx; i <= n - days; i++) {
            mx = max(mx, job[i]);
            int next = solve(job, i + 1, n, days - 1);
            ans = min(ans, mx + next);
        }

        return t[idx][days] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        memset(t, -1, sizeof(t));
        return solve(jobDifficulty, 0, n, d);
    }
};