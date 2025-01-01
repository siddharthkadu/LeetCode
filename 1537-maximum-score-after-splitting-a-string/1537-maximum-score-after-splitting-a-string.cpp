class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int res = 0;

        int count_zero_left = 0;
        int count_one_right = 0;

        // Split it into two portions
        for (int i = 0; i <= n - 2; i++) {
            // Count 0 to i for the number of zeros
            count_zero_left = 0; // Reset count for each split
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0') { // Fixed comparison to use single quotes
                    count_zero_left++;
                }
            }

            // Count i+1 to n-1 for the number of ones
            count_one_right = 0; // Reset count for each split
            for (int j = i + 1; j <= n - 1; j++) {
                if (s[j] == '1') { // Fixed comparison to use single quotes
                    count_one_right++;
                }
            }

            // Update the result with the maximum score
            res = max(res, count_zero_left + count_one_right);
        }

        return res;
    }
};
