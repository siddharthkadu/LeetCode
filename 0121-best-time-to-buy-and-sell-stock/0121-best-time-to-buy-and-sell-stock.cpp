class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the minimum price as the first day's price
        int minI = prices[0];
        
        // Initialize the maximum profit to 0
        int maxprofit = 0;
        
        // Variable to store the cost (profit for the current day)
        int cost;

        // Traverse through the prices starting from the second day
        // We start from index 1 because we set the initial minimum price to the first day's price
        for (int i = 1; i < prices.size(); i++) {
            // Calculate the profit if selling on the current day (i)
            cost = prices[i] - minI;

            // Update the maximum profit encountered so far
            maxprofit = max(maxprofit, cost);

            // Update the minimum price encountered so far
            minI = min(minI, prices[i]);
        }

        // Return the maximum profit
        return maxprofit;
    }
};
