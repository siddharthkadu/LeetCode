class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize the distance matrix
    const int INF = INT_MAX / 2; // Avoid overflow when adding weights
    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0; // Distance from a city to itself is 0
    }

    for (const auto& edge : edges) {
        int from = edge[0], to = edge[1], weight = edge[2];
        dist[from][to] = weight;
        dist[to][from] = weight; // Bidirectional edge
    }

    // Step 2: Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Step 3: Count reachable cities for each city
    int minReachable = n;
    int resultCity = -1;

    for (int i = 0; i < n; i++) {
        int reachableCount = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold) {
                reachableCount++;
            }
        }

        // Step 4: Update result based on criteria
        if (reachableCount < minReachable || (reachableCount == minReachable && i > resultCity)) {
            minReachable = reachableCount;
            resultCity = i;
        }
    }

    return resultCity;
    }
};