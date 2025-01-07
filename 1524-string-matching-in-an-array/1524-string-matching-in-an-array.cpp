class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
                vector<string> result;

        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = 0; j < words.size(); j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; // No need to check further; move to the next word
                }
            }
        }

        return result;
    }

    
};