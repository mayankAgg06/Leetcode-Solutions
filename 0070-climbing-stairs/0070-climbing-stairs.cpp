class Solution {
public:
    int dp[50]={0};

    int climbStairs(int n) {
        if(n<0) return -1;

        if(n==0) return 1;

        if(dp[n]) return dp[n];

        int one = climbStairs(n-1);
        int two = climbStairs(n-2);

        if(one != -1 ) dp[n] += one;
        if(two != -1 ) dp[n] += two;
        
        return dp[n];

    }
};