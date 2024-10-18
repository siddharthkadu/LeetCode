class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // Step 1: Find the maximum possible bitwise OR value
        int max_or = 0;
        for (int num : nums) {
            max_or |= num;
        }

        // Step 2: Helper function to count subsets with maximum OR
        return countSubsets(nums, 0, 0, max_or);
    }

private:
    // Recursive function to count subsets
    int countSubsets(vector<int>& nums, int index, int current_or, int max_or) {
        // If we have considered all elements, check if the current OR is max OR
        if (index == nums.size()) {
            return (current_or == max_or) ? 1 : 0;
        }

        // Include the current element in the subset OR
        int include = countSubsets(nums, index + 1, current_or | nums[index], max_or);

        // Exclude the current element from the subset OR
        int exclude = countSubsets(nums, index + 1, current_or, max_or);

        // Return the sum of both possibilities
        return include + exclude;
    }
};