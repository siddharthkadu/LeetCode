class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

   std::unordered_map<int, int> remainderFreq;

    // Count the frequency of each remainder when elements are divided by k
    for (int num : arr) {
        int remainder = ((num % k) + k) % k;  // Handle negative numbers
        remainderFreq[remainder]++;
    }

    // Check for each remainder
    for (const auto& [remainder, count] : remainderFreq) {
        if (remainder == 0) {
            // If remainder is 0, we must have an even count (paired within themselves)
            if (count % 2 != 0) return false;
        } else if (2 * remainder == k) {
            // If remainder is exactly k/2 (when k is even), we must have an even count
            if (count % 2 != 0) return false;
        } else {
            // General case: remainder r should be paired with k - r
            if (remainderFreq[remainder] != remainderFreq[k - remainder]) return false;
        }
    }

    return true;
}
};