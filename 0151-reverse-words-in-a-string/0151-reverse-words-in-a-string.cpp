class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Trim leading and trailing spaces
        int start = 0, end = s.size() - 1;
        
        // Remove leading spaces
        while (start <= end && s[start] == ' ') {
            start++;
        }
        
        // Remove trailing spaces
        while (start <= end && s[end] == ' ') {
            end--;
        }

        // If the string becomes empty after trimming
        if (start > end) return "";
        
        // Step 2: Extract words and store them
        vector<string> words;
        string word = "";
        for (int i = start; i <= end; i++) {
            if (s[i] != ' ') {
                word += s[i];  // Build the current word
            } else {
                if (!word.empty()) {
                    words.push_back(word); // Push the word to the vector
                    word = ""; // Reset word
                }
            }
        }
        // Add the last word if exists
        if (!word.empty()) {
            words.push_back(word);
        }

        // Step 3: Reverse the words
        reverse(words.begin(), words.end());

        // Step 4: Join the words with a single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " "; // Add space between words, but not after the last one
            }
        }
        
        return result;
    }
};
