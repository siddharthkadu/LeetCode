class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> positions;
        vector<int> result(s.size(), INT_MAX);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                positions.push_back(i);
            }
        }

    
        for (int i = 0; i < s.size(); i++) {
            for (int pos : positions) {
                result[i] = min(result[i], abs(i - pos));
            }
        }

        return result;
    }
};
