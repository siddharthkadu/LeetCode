class Solution {
public:
    // Helper function for DFS to collect fish
    int dfs(int r, int c, vector<vector<int>>& grid) {
        // Check if the current cell is invalid or already visited
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] <= 0) {
            return 0;
        }
        
        // Collect the fish in the current cell and mark it as visited
        int fish = grid[r][c];
        grid[r][c] = 0; // Mark as visited by setting to 0
        
        // Explore all 4 directions
        fish += dfs(r + 1, c, grid);
        fish += dfs(r - 1, c, grid);
        fish += dfs(r, c + 1, grid);
        fish += dfs(r, c - 1, grid);
        
        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        // Iterate through each cell in the grid
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Start DFS from any water cell
                if (grid[r][c] > 0) {
                    maxFish = max(maxFish, dfs(r, c, grid));
                }
            }
        }
        
        return maxFish;
    }
};
