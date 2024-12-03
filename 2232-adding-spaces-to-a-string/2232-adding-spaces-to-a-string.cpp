class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str;
        str.reserve(s.size() + spaces.size()); // Reserve space for efficiency
        int j = 0; // Pointer for the `spaces` vector

        for (int i = 0; i < s.size(); i++) {
            if (j < spaces.size() && i == spaces[j]) {
                str.push_back(' '); // Append a space character
                j++;
            }
            str.push_back(s[i]); // Append the current character from `s`
        }
        
        return str;
    }
};
