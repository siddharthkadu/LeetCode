class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        for(int i = 0; i < nums1.size(); i++) {
            result.push_back(nums1[i]);
        }
        
        for(int i = 0; i < nums2.size(); i++) {
            result.push_back(nums2[i]);
        }
        
        sort(result.begin(), result.end());
        
        int totalSize = result.size();
        
        if (totalSize % 2 == 1) {
            return result[totalSize / 2];
        } else {
            return (result[totalSize / 2 - 1] + result[totalSize / 2]) / 2.0;
        }
    }
};