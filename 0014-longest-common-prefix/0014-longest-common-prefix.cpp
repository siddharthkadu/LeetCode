class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
          if (strs.empty()) return ""; // Handle edge case: empty array

    string prefix = strs[0]; // Start with the first string as the initial prefix
    
    // Iterate through all strings in the array
    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        // Compare characters until they match
        while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
            j++;
        }
        // Update the prefix to the matched portion
        prefix = prefix.substr(0, j);
        // If the prefix becomes empty, no common prefix exists
        if (prefix.empty()) return "";
    }
    return prefix;
    }
};