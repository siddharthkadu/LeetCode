class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> reversedGraph(n); // Reversed edges of the graph
    vector<int> outDegree(n, 0); // Outdegree for each node

    // Reverse the graph and calculate the outdegree
    for (int i = 0; i < n; i++) {
        for (int neighbor : graph[i]) {
            reversedGraph[neighbor].push_back(i);
        }
        outDegree[i] = graph[i].size();
    }

    queue<int> q;
    // Add terminal nodes (nodes with 0 outdegree) to the queue
    for (int i = 0; i < n; i++) {
        if (outDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> safeNodes;

    // Perform reverse BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for (int neighbor : reversedGraph[node]) {
            outDegree[neighbor]--;
            if (outDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Sort the safe nodes in ascending order
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}
};