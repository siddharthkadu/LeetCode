class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m < 3 || n < 3) return 0; // Not enough space to trap water
        
        // Min-heap to store the cells, sorted by height
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        
        // Visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Add all boundary cells to the heap
        for (int i = 0; i < m; i++) {
            for (int j : {0, n - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i : {0, m - 1}) {
                if (!visited[i][j]) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        // Directions for moving to neighbors (up, down, left, right)
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int water = 0;
        
        while (!minHeap.empty()) {
            auto [h, cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first, y = cell.second;
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // Water trapped at this cell
                    water += max(0, h - heightMap[nx][ny]);
                    // Add the neighbor to the heap with updated height
                    minHeap.push({max(h, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }
        
        return water;
    }
};
