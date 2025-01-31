
class Solution {
public:
    int n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    // DFS to label islands and calculate their sizes
    int dfs(vector<vector<int>>& grid, int i, int j, int islandID) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return 0;

        grid[i][j] = islandID; // Mark cell with islandID
        int size = 1;
        
        for (auto& dir : directions)
            size += dfs(grid, i + dir[0], j + dir[1], islandID);
        
        return size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize; // {islandID -> size}
        int islandID = 2;  // Start from 2 to differentiate from 0 and 1
        int maxSize = 0;

        // Step 1: Label each island and store its size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandID);
                    islandSize[islandID] = size;
                    maxSize = max(maxSize, size);
                    islandID++;
                }
            }
        }

        // Step 2: Check each 0 to find max possible island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIslands;
                    int newSize = 1;  // Flipping 0 to 1

                    // Check all 4 neighbors
                    for (auto& dir : directions) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1) {
                            uniqueIslands.insert(grid[x][y]);
                        }
                    }

                    // Sum up sizes of unique neighboring islands
                    for (int island : uniqueIslands) {
                        newSize += islandSize[island];
                    }

                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return maxSize;
    }
};
