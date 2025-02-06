class Solution {
public:
  int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> productCount;
    int count = 0;

    // Iterate through all pairs (a, b)
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int product = nums[i] * nums[j];

            // If this product has been seen before, add to count
            if (productCount.find(product) != productCount.end()) {
                count += productCount[product] * 8; // Each pair contributes 8 permutations
            }

            // Store the product frequency
            productCount[product]++;
        }
    }

    return count;
}
};