#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        if (n == 0) return -1; // Edge case: empty string

        unordered_map<string, int> freq;
        int maxLength = -1;

        // Iterate through the string to find special substrings
        for (int i = 0; i < n; ++i) {
            char currentChar = s[i];
            string special = "";
            for (int j = i; j < n && s[j] == currentChar; ++j) {
                special += currentChar;
                freq[special]++;
                if (freq[special] >= 3) {
                    maxLength = max(maxLength, (int)special.size());
                }
            }
        }

        return maxLength;
    }
};
