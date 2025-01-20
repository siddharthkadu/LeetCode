class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    unordered_map<int, pair<int, int>> positionMap;

    // Map each number to its (row, col) position in mat
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            positionMap[mat[i][j]] = {i, j};
        }
    }

    vector<int> rowCount(m, 0); // Count of painted cells in each row
    vector<int> colCount(n, 0); // Count of painted cells in each column

    // Process the elements in arr
    for (int i = 0; i < arr.size(); i++) {
        auto [row, col] = positionMap[arr[i]];

        // Paint the cell and update counts
        rowCount[row]++;
        colCount[col]++;

        // Check if the row or column is completely painted
        if (rowCount[row] == n || colCount[col] == m) {
            return i;
        }
    }

    // This point is never reached given the problem constraints
    return -1;
}
};