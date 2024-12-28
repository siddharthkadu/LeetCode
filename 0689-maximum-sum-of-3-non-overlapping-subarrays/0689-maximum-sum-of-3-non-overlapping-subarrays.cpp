class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0); // Prefix sum for easy sum computation
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    vector<int> left(n, 0), right(n, 0);
    int maxSum = 0;

    // Calculate best left subarray indices
    for (int i = k - 1; i < n; ++i) {
        int sum = prefixSum[i + 1] - prefixSum[i + 1 - k];
        if (i == k - 1 || sum > maxSum) {
            left[i] = i - k + 1;
            maxSum = sum;
        } else {
            left[i] = left[i - 1];
        }
    }

    // Calculate best right subarray indices
    maxSum = 0;
    for (int i = n - k; i >= 0; --i) {
        int sum = prefixSum[i + k] - prefixSum[i];
        if (i == n - k || sum >= maxSum) {
            right[i] = i;
            maxSum = sum;
        } else {
            right[i] = right[i + 1];
        }
    }

    // Find the best middle subarray
    maxSum = 0;
    vector<int> result(3, -1);
    for (int i = k; i <= n - 2 * k; ++i) {
        int leftIdx = left[i - 1];
        int rightIdx = right[i + k];
        int currentSum = (prefixSum[leftIdx + k] - prefixSum[leftIdx]) +
                         (prefixSum[i + k] - prefixSum[i]) +
                         (prefixSum[rightIdx + k] - prefixSum[rightIdx]);
        if (currentSum > maxSum) {
            maxSum = currentSum;
            result = {leftIdx, i, rightIdx};
        }
    }

    return result;
}
};