class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7; // Define the modulus to keep the numbers within the integer limit
        int targetLength = target.size(), wordLength = words[0].size(); // Size of the target string and length of each word in the array
        vector<vector<int>> count(wordLength, vector<int>(26)); // 2D vector to store the count of each character at each position
      
        // Loop to count the frequency of each character at each column in the word list
        for (auto& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                ++count[j][word[j] - 'a']; // Increment the count of the character at the relevant position
            }
        }

        // DP array initialized with -1 to indicate that the value hasn't been computed yet
        int dp[targetLength][wordLength];
        memset(dp, -1, sizeof(dp));
      
        // Recursive lambda function to compute the number of ways using Depth First Search (DFS)
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i >= targetLength) {
                return 1; // If the whole target is found, return 1 way
            }
            if (j >= wordLength) {
                return 0; // If the end of the word is reached, no more ways can be found, return 0
            }
            if (dp[i][j] != -1) {
                return dp[i][j]; // If the value is already computed, return the cached result
            }
            int ways = dfs(i, j + 1); // Recursive call to check for ways without using the current position
            ways = (ways + 1LL * dfs(i + 1, j + 1) * count[j][target[i] - 'a']) % MOD; // Add the ways using the current character and proceed
            return dp[i][j] = ways; // Store the computed ways in the DP array for memoization
        };
      
        // Call the DFS function starting from the first character of the target and the word
        return dfs(0, 0);
    }
};