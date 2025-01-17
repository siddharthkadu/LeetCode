class Solution {
public:
  bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();

    // Try both possible values for original[0]: 0 and 1
    for (int first = 0; first <= 1; ++first) {
        vector<int> original(n);
        original[0] = first;

        // Reconstruct the original array using derived
        for (int i = 0; i < n - 1; ++i) {
            original[i + 1] = original[i] ^ derived[i];
        }

        // Check if the last XOR condition holds: original[n-1] ⊕ original[0] == derived[n-1]
        if ((original[n - 1] ^ original[0]) == derived[n - 1]) {
            return true;  // A valid original array exists
        }
    }
    
    return false;  // No valid original array found
}
};