class Solution {
public:
    bool canConstruct(string s, int k) {
         if (s.length() < k) return false;

    unordered_map<char, int> freq;
    
    // Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    int oddCount = 0;
    
    // Count characters with odd frequencies
    for (auto& [key, value] : freq) {
        if (value % 2 != 0) {
            oddCount++;
        }
    }

    // If odd characters exceed k, it's impossible
    return oddCount <= k;
        
    }
};