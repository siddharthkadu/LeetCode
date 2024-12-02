class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int wordIndex = 1; // To keep track of the word index
        int start = 0; // Start of the current word
        
        for (int i = 0; i <= n; ++i) {
            // Check for word boundary (space or end of string)
            if (i == n || sentence[i] == ' ') {
                // Check if the current word starts with searchWord
                if (sentence.substr(start, searchWord.size()) == searchWord) {
                    return wordIndex;
                }
                // Move to the next word
                wordIndex++;
                start = i + 1;
            }
        }
        
        return -1; // No word found with the given prefix
    }
};
