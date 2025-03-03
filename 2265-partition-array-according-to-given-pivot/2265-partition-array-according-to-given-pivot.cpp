#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int lCount = 0, pCount = 0;
        
        // Count elements < pivot and == pivot
        for (int num : nums) {
            if (num < pivot) lCount++;
            else if (num == pivot) pCount++;
        }

        int left = 0, mid = lCount, right = lCount + pCount;
        vector<int> res(nums.size());

        // Place elements in the correct positions
        for (int num : nums) {
            if (num < pivot) {
                res[left++] = num;
            } else if (num > pivot) {
                res[right++] = num;
            } else {
                res[mid++] = num;
            }
        }

        return res;
    }
};