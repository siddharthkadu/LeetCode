class Solution {
public:
    bool check(vector<int>& nums) {
        int countBreaks = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Check if current element is greater than next element (modulo to wrap around)
            if (nums[i] > nums[(i + 1) % n]) {
                countBreaks++;
            }
            if (countBreaks > 1) {
                return false; // More than one break means it's not a rotated sorted array
            }
        }
        
        return true;
    }
};