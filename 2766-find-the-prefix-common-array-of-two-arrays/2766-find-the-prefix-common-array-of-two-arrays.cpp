class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n, 0);  // Result vector to store the prefix common count
        int commonCount = 0;    // Counter for common elements

        int i = 0;  // Pointer for the prefix
        while (i < n) {
            int j = 0;
            while (j <= i) {  // Iterate through A[0...i]
                int k = 0;
                while (k <= i) {  // Iterate through B[0...i]
                    if (A[j] == B[k]) {
                        commonCount++;
                        break;  // Avoid counting duplicates
                    }
                    k++;
                }
                j++;
            }
            res[i] = commonCount;  // Store the common count for this prefix
            commonCount = 0;       // Reset for the next prefix
            i++;
        }

        return res;
    }
};