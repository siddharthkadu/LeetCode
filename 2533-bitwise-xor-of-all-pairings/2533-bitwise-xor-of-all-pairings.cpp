class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

     int xor1 = 0, xor2 = 0;

    // XOR all elements in nums1 if nums2 has an odd length
    if (nums2.size() % 2 != 0) {
        for (int num : nums1) {
            xor1 ^= num;
        }
    }

    // XOR all elements in nums2 if nums1 has an odd length
    if (nums1.size() % 2 != 0) {
        for (int num : nums2) {
            xor2 ^= num;
        }
    }

    return xor1 ^ xor2;
}
};
