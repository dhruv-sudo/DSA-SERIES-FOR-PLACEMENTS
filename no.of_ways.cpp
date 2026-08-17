class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int rearrangeSticks(int n, int k) {
        // dp[j] = number of ways for current number of sticks
        // to have exactly j visible sticks.
        vector<long long> dp(k + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            vector<long long> next(k + 1, 0);

            for (int j = 1; j <= min(i, k); ++j) {
                // Put the largest stick at the front.
                // It becomes a new visible stick.
                next[j] = dp[j - 1];

                // Put the largest stick somewhere after the front.
                // It hides one of the existing positions.
                next[j] += (long long)(i - 1) * dp[j];

                next[j] %= MOD;
            }

            dp.swap(next);
        }

        return dp[k];
    }
};
