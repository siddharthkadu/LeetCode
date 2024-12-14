class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        int left = 0; // Left pointer of the sliding window
        multiset<int> window; // To track the min and max of the current window
        
        for (int right = 0; right < nums.size(); ++right) {
            window.insert(nums[right]);
            
            // Ensure the condition |max - min| <= 2
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                left++;
            }
            
            // Add the count of subarrays ending at 'right'
            count += (right - left + 1);
        }
        
        return count;
    }
};
