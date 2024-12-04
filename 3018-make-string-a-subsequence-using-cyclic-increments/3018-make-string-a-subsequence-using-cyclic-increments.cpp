class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
int i = 0, j = 0; // Pointers for str1 and str2
    
    while (i < str1.length() && j < str2.length()) {
        // Check if current characters match directly
        if (str1[i] == str2[j]) {
            j++;
        }
        // Check if current character in str1 can be transformed to match str2[j]
        else if ((str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
            j++;
        }
        // Move to the next character in str1
        i++;
    }
    
    // If we traversed all characters in str2, return true
    return j == str2.length();
    }
};