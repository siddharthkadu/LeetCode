class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // Initialize parent array
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        // Find function with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);  // Path compression
            return parent[x];
        };
        
        // Union function
        auto unionSets = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return false; // Cycle detected
            
            parent[rootY] = rootX; // Union
            return true;
        };
        
        // Process each edge
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            
            if (!unionSets(u, v)) {
                return edge; // This edge creates a cycle
            }
        }
        
        return {}; // This won't happen as input guarantees a redundant edge
    }
};
