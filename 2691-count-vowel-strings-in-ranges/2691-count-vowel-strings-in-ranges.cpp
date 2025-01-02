class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1, 0); // Prefix sum array
        
        // Step 1: Build the prefix sum array
        for (int i = 0; i < n; ++i) {
            string str = words[i];
            int l = str.size() - 1;
            if ((str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u') &&
                (str[l] == 'a' || str[l] == 'e' || str[l] == 'i' || str[l] == 'o' || str[l] == 'u')) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }
        
        // Step 2: Answer each query using the prefix sum array
        vector<int> ans;
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            ans.push_back(prefixSum[end + 1] - prefixSum[start]);
        }
        
        return ans;
    }
};
