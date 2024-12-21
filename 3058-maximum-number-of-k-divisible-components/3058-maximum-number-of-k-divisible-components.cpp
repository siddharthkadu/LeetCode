class Solution {
public:
    int maxComponents = 1; // To count the maximum number of components

    long long dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& values, int k) {
        long long subtreeSum = values[node]; // Use long long to prevent overflow

        // Explore all neighbors of the current node
        for (int neighbor : tree[node]) {
            if (neighbor == parent) continue; // Skip the parent node to avoid cycling

            // Recursively calculate the sum of the subtree rooted at the neighbor
            long long childSum = dfs(neighbor, node, tree, values, k);

            // If the child subtree sum is divisible by k, we can consider cutting this edge
            if (childSum % k == 0) {
                maxComponents++;
            } else {
                subtreeSum += childSum; // Otherwise, add the sum to the current subtree
            }
        }

        return subtreeSum; // Return the total sum of the current subtree
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> tree(n); // Adjacency list to represent the tree

        // Build the tree from the given edges
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Start DFS from node 0 with -1 as its parent
        dfs(0, -1, tree, values, k);

        return maxComponents; // Return the maximum number of components
    }
};