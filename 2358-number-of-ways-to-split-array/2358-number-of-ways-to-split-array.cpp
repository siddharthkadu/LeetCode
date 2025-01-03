class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0; // Use long long to handle large numbers
        for (int num : nums) {
            totalSum += num; // Compute total sum
        }

        long long prefixSum = 0;
        int count = 0;

        for (int i = 0; i < n - 1; i++) { // Traverse up to n-2
            prefixSum += nums[i]; // Update prefix sum
            long long suffixSum = totalSum - prefixSum; // Compute suffix sum
            if (prefixSum >= suffixSum) { // Check if it's a valid split
                count++;
            }
        }

        return count;
    }
};
