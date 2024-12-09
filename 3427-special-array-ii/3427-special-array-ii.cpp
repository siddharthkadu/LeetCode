#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief Performs binary search to check if there exists any "violating index" 
     *        in the range [sp, ep] within the sorted list `vi`.
     * 
     * @param vi The sorted list of violating indices.
     * @param sp The starting index of the range (inclusive).
     * @param ep The ending index of the range (inclusive).
     * @return true if there is at least one violating index in the range, false otherwise.
     */
    bool bSearch(const vector<int>& vi, int sp, int ep) {
        int l = 0;                // Initialize the left pointer
        int r = vi.size() - 1;    // Initialize the right pointer

        while (l <= r) {          // Standard binary search loop
            int mid = l + (r - l) / 2; // Calculate the mid-point to avoid overflow

            if (vi[mid] < sp) {
                // If the mid-point is less than the range start, move the left pointer right
                l = mid + 1;
            } else if (vi[mid] > ep) {
                // If the mid-point is greater than the range end, move the right pointer left
                r = mid - 1;
            } else {
                // If the mid-point lies within the range [sp, ep], return true
                return true;
            }
        }

        // If no violating index is found in the range, return false
        return false;
    }

    /**
     * @brief Determines if subarrays defined by queries are "special". A subarray is
     *        considered "special" if all its adjacent elements have different parities.
     * 
     * @param nums The input array of integers.
     * @param queries A list of queries, where each query defines a subarray range [start, end].
     * @return A vector of boolean values where each element corresponds to a query, 
     *         indicating whether the subarray is special or not.
     */
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();  // Number of queries
        int n = nums.size();     // Size of the input array

        vector<int> vi; // List of indices where adjacent elements have the same parity

        // Identify all "violating indices" where nums[i] and nums[i-1] have the same parity
        for (int i = 1; i < n; i++) { // Loop starts from 1 since we compare with the previous element
            if (nums[i] % 2 == nums[i - 1] % 2) {
                // If nums[i] and nums[i-1] have the same parity, record the index
                vi.push_back(i);
            }
        }

        // Result vector to store the answer for each query
        vector<bool> result(m, false);

        // Process each query to determine if the corresponding subarray is special
        for (int i = 0; i < m; i++) {
            int start = queries[i][0]; // Starting index of the query range
            int end = queries[i][1];   // Ending index of the query range

            // Use binary search to check if there are violating indices in the range [start+1, end]
            bool hasViolatingIndexInRange = bSearch(vi, start + 1, end);

            // If no violating index is found, the subarray is special
            if (!hasViolatingIndexInRange) {
                result[i] = true;
            }
        }

        return result; // Return the results for all queries
    }
};
