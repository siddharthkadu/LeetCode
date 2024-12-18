class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st; // Monotonic stack to store indices
        for (int i = 0; i < prices.size(); i++) {
            // Check for discounts while stack is not empty
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop(); // Remove the index after applying the discount
            }
            st.push(i); // Push current index onto the stack
        }
        return prices;
    }
};
