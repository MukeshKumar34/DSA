
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Step 1: Calculate cost of every window
        vector<long long> cost;
        
        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        for (int i = 0; i < n; i++) {
            
            // Insert current element
            if (left.empty() || nums[i] <= *left.rbegin()) {
                left.insert(nums[i]);
                leftSum += nums[i];
            } else {
                right.insert(nums[i]);
                rightSum += nums[i];
            }

            // Remove element outside current window
            if (i >= x) {
                int out = nums[i - x];

                auto it = left.find(out);

                if (it != left.end()) {
                    left.erase(it);
                    leftSum -= out;
                } else {
                    right.erase(right.find(out));
                    rightSum -= out;
                }
            }

            // Balance both sets
            if (left.size() < right.size()) {
                int val = *right.begin();

                right.erase(right.begin());
                left.insert(val);

                rightSum -= val;
                leftSum += val;
            }

            if (left.size() > right.size() + 1) {
                int val = *left.rbegin();

                left.erase(prev(left.end()));
                right.insert(val);

                leftSum -= val;
                rightSum += val;
            }

            // Calculate cost when window size becomes x
            if (i >= x - 1) {
                long long median = *left.rbegin();

                long long operations =
                    median * left.size() - leftSum
                    + rightSum - median * right.size();

                cost.push_back(operations);
            }
        }

        // Step 2: Dynamic Programming
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {

                if (dp[i][j] == INF) continue;

                // Option 1: Skip current index
                dp[i + 1][j] = min(
                    dp[i + 1][j],
                    dp[i][j]
                );

                // Option 2: Select window
                if (j < k && i + x <= n) {
                    dp[i + x][j + 1] = min(
                        dp[i + x][j + 1],
                        dp[i][j] + cost[i]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
