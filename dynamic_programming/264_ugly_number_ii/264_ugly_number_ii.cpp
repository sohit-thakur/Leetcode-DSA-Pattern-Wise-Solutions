class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int i2=0;
        int i3=0;
        int i5=0;
        for(int i=1;i<n;i++){
            long i2ugly = dp[i2]*2;
            long i3ugly = dp[i3]*3;
            long i5ugly = dp[i5]*5;
            dp[i] = min({i2ugly,i3ugly,i5ugly});
            if(dp[i]==i2ugly) i2++;
            if(dp[i]==i3ugly) i3++;
            if(dp[i]==i5ugly) i5++;
        }
        return dp[n-1];
    }
};