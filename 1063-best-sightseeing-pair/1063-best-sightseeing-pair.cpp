class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
    int maxScore = 0;  // Stores the maximum score found so far
    int maxLeft = values[0];  // Keeps track of the best value[i] + i seen so far

    for (int j = 1; j < values.size(); ++j) {
        // Calculate the score for the pair (i, j) where i < j
        maxScore = max(maxScore, maxLeft + values[j] - j);
        // Update maxLeft to include the current values[j] + j
        maxLeft = max(maxLeft, values[j] + j);
    }

    return maxScore;
}
};