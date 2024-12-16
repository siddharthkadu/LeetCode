#include <vector>
#include <algorithm> // For min_element
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int count = 0; count < k; count++) {
            // Find the minimum value in the array
            auto minIt = min_element(nums.begin(), nums.end());
            
            // Multiply the minimum value by the multiplier
            *minIt *= multiplier;
        }
        return nums;
    }
};
