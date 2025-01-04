
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> leftSeen(26, 0);    // Tracks if a character has appeared to the left
        vector<int> rightCount(26, 0); // Tracks count of characters to the right

        // Initialize rightCount with frequencies of all characters
        for (char c : s) {
            rightCount[c - 'a']++;
        }

        unordered_set<string> uniquePalindromes; // To ensure uniqueness

        // Iterate through the string, treating each character as the middle one
        for (int i = 0; i < n; i++) {
            char middle = s[i];
            rightCount[middle - 'a']--; // Remove current character from right count

            // Check for palindromes of the form a_x_a
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (leftSeen[ch - 'a'] > 0 && rightCount[ch - 'a'] > 0) {
                    string palindrome = string() + ch + middle + ch;
                    uniquePalindromes.insert(palindrome);
                }
            }

            // Mark the current character as seen on the left
            leftSeen[middle - 'a']++;
        }

        return uniquePalindromes.size();
    }
};