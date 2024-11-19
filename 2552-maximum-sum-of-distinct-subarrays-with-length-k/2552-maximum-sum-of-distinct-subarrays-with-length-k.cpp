class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> windowElements;
        long long windowSum = 0, maxSum = 0; // Use long long for larger sums
        int start = 0;

        for (int end = 0; end < n; ++end) {
            // Remove duplicates by shrinking the window from the left
            while (windowElements.count(nums[end])) {
                windowSum -= nums[start];
                windowElements.erase(nums[start]);
                ++start;
            }

            // Add the current element to the window
            windowSum += nums[end];
            windowElements.insert(nums[end]);

            // Check if the window size is exactly k
            if (end - start + 1 == k) {
                maxSum = max(maxSum, windowSum);

                // Slide the window by removing the leftmost element
                windowSum -= nums[start];
                windowElements.erase(nums[start]);
                ++start;
            }
        }

        return maxSum;
    }
};