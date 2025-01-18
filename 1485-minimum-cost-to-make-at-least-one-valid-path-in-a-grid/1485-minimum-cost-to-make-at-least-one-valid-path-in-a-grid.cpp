class Solution {
public:
      int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        
        // Directions: Right, Left, Down, Up
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        dq.push_front({0, 0});
        cost[0][0] = 0;
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            for (int d = 0; d < 4; ++d) {
                int newX = x + directions[d].first;
                int newY = y + directions[d].second;
                int newCost = cost[x][y] + (grid[x][y] == d + 1 ? 0 : 1);
                
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && newCost < cost[newX][newY]) {
                    cost[newX][newY] = newCost;
                    if (grid[x][y] == d + 1) {
                        dq.push_front({newX, newY});
                    } else {
                        dq.push_back({newX, newY});
                    }
                }
            }
        }
        
        return cost[m - 1][n - 1];
    }
};