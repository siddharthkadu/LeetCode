class Solution {
public:
   bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2) return true;  // If both strings are already equal
    
    vector<int> diffIndices;
    
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            diffIndices.push_back(i);
            if (diffIndices.size() > 2) return false;  // More than 2 mismatches, return false
        }
    }
    
    if (diffIndices.size() != 2) return false;  // If not exactly two mismatches, return false
    
    // Check if swapping the two mismatched characters in s1 makes it equal to s2
    return (s1[diffIndices[0]] == s2[diffIndices[1]] && s1[diffIndices[1]] == s2[diffIndices[0]]);
}
};