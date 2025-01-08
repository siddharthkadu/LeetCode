class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        if (len1 > len2) return false;

        // Check if str1 is a prefix of str2
        bool isPrefix = (str2.substr(0, len1) == str1);

        // Check if str1 is a suffix of str2
        bool isSuffix = (str2.substr(len2 - len1) == str1);

        return isPrefix && isSuffix;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        // Iterate through all pairs (i, j) where i < j
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};
