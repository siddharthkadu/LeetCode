class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle division by zero
        if (divisor == 0) {
            throw std::invalid_argument("Divisor cannot be zero");
        }
        
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Return the maximum value for 32-bit integer
        }
        
        // Perform division
        int ans = dividend / divisor;
        
        return ans;
    } 
};
