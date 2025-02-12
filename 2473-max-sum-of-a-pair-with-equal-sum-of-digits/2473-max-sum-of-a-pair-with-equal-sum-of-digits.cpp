class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> digitSumMap;
        int maxSum = -1;
        
        // Group numbers by their digit sum
        for (int num : nums) {
            int sumDigits = getDigitSum(num);
            digitSumMap[sumDigits].push_back(num);
        }
        
        // Find the max sum of two numbers in the same group
        for (auto& [key, values] : digitSumMap) {
            if (values.size() > 1) {
                sort(values.rbegin(), values.rend()); // Sort in descending order
                maxSum = max(maxSum, values[0] + values[1]);
            }
        }
        
        return maxSum;
    }

private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
