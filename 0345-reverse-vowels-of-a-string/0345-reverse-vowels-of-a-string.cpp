class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        
        // Check if a character is a vowel
        auto isVowel = [](char c) {
            return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                   c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        while (l < r) {
            // Move left pointer to the next vowel
            while (l < r && !isVowel(s[l])) {
                l++;
            }
            
            // Move right pointer to the previous vowel
            while (l < r && !isVowel(s[r])) {
                r--;
            }
            
            // Swap vowels
            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        
        return s;
    }
};
