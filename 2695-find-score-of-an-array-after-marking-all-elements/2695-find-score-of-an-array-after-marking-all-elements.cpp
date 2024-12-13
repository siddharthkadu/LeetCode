class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false); // to track marked elements
        long long score = 0; // Use long long for large sum handling
        
        // Create a vector of pairs (value, index) and sort by value then index
        vector<pair<int, int>> sorted_nums;
        for (int i = 0; i < n; ++i) {
            sorted_nums.push_back({nums[i], i});
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        
        // Process the sorted array
        for (auto& num : sorted_nums) {
            int value = num.first;
            int index = num.second;
            
            // If the element is already marked, skip it
            if (marked[index]) continue;
            
            // Add to score
            score += value;
            
            // Mark the current element and its adjacent elements if they exist
            marked[index] = true;
            if (index - 1 >= 0) marked[index - 1] = true;
            if (index + 1 < n) marked[index + 1] = true;
        }
        
        return score;
    }
};
