class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns
        int count = 0;
   

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    bool mark = false;

                    // Check the row for another server   (take connstant row only traversal throgh column )
                    for (int col = 0; col < n; col++) {
                        if (grid[i][col] == 1 && col != j) {
                            mark = true;
                            break;
                        }
                    }
                    

                    // Check the column for another server if no server found in the row
                    if (!mark) {
                        for (int row = 0; row < m; row++) {
                            if (grid[row][j] == 1 && row != i) {
                                mark = true;
                                break;
                            }
                        }
                    }

                    // Increment count if this server can communicate
                    if (mark) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
