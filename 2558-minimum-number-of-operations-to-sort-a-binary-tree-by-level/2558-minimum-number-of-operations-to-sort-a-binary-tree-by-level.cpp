/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// Function to calculate minimum swaps to sort an array
int minSwapsToSort(vector<int>& arr) {
    vector<pair<int, int>> indexedArr;
    for (int i = 0; i < arr.size(); ++i) {
        indexedArr.push_back({arr[i], i});
    }

    // Sort the array based on values
    sort(indexedArr.begin(), indexedArr.end());

    vector<bool> visited(arr.size(), false);
    int swaps = 0;

    for (int i = 0; i < arr.size(); ++i) {
        // If already visited or in correct position, skip
        if (visited[i] || indexedArr[i].second == i) continue;

        // Count the size of the cycle
        int cycleSize = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = indexedArr[j].second;
            ++cycleSize;
        }

        // Add the swaps for the current cycle
        if (cycleSize > 1) swaps += (cycleSize - 1);
    }

    return swaps;
}


    int minimumOperations(TreeNode* root) {
         if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int totalSwaps = 0;

    while (!q.empty()) {
        int size = q.size();
        vector<int> levelValues;

        // Process the current level
        for (int i = 0; i < size; ++i) {
            TreeNode* current = q.front();
            q.pop();
            levelValues.push_back(current->val);

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        // Calculate swaps required to sort the current level
        totalSwaps += minSwapsToSort(levelValues);
    }

    return totalSwaps;
              
    }
};

