


class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(n + 1, -1);  // -1: unvisited, 0 and 1: two colors
        int maxGroups = 0;
        
        function<int(int)> bfs = [&](int start) {
            queue<int> q;
            vector<int> dist(n + 1, -1);
            q.push(start);
            dist[start] = 0;
            int maxDepth = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                maxDepth = max(maxDepth, dist[node]);

                for (int neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                    }
                }
            }
            return maxDepth + 1; // Total groups in this component
        };

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {  // New connected component
                queue<int> q;
                q.push(i);
                color[i] = 0;
                bool isBipartite = true;
                vector<int> component;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);

                    for (int neighbor : adj[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return -1;  // Odd cycle found, not bipartite
                        }
                    }
                }

                // Compute max depth in this component using BFS
                int maxDepth = 0;
                for (int node : component) {
                    maxDepth = max(maxDepth, bfs(node));
                }
                maxGroups += maxDepth;
            }
        }

        return maxGroups;
    }
};