class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Sort the array to efficiently handle the ranges
        sort(nums.begin(), nums.end());

        // Two pointers to check ranges
        int sp = 0; // Start pointer

        for (int ep = 0; ep < n; ep++) {
            // Expand the range [nums[sp], nums[ep]]
            while (nums[ep] - nums[sp] > 2 * k) {
                sp++; // Shrink the range if difference exceeds 2*k
            }
            // The range [nums[sp], nums[ep]] is valid
            count = max(count, ep - sp + 1);
        }

        return count;
    }
};
