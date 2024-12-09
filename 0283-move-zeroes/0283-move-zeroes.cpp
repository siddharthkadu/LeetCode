class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;  // Position to place the next non-zero element
        
        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt] = nums[i];  // Place non-zero element at the lastNonZeroFoundAt position
                lastNonZeroFoundAt = lastNonZeroFoundAt + 1;  // Increment position for the next non-zero element
            }
        }
        
        // Fill the remaining positions with zeros
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
