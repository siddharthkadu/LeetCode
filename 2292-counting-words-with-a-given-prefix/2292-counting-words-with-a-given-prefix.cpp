class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            // Check if the prefix matches the start of the word
            if (words[i].substr(0, pref.size()) == pref) {
                count++;
            }
        }
        return count;
    }
};
