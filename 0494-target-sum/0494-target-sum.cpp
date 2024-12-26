#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // If the target is not achievable, return 0
        if (sum < abs(target) || (sum + target) % 2 != 0) {
            return 0;
        }

        // Calculate subset sum
        int subsetSum = (sum + target) / 2;

        // DP array to count subsets with a given sum
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // There's one way to make sum 0 (empty subset)

        for (int num : nums) {
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};
