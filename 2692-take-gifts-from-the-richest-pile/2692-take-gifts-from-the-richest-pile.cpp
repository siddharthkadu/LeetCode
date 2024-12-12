class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Sort the gifts array
        sort(gifts.begin(), gifts.end());
        int count = 0; // Counter for iterations
        long long sum = 0; // To store the total sum

        // Repeat the process k times
        while (count < k) {
            // Find the maximum element in the vector
            auto max_it = max_element(gifts.begin(), gifts.end());
            if (max_it == gifts.end()) break; // Safety check

            // Calculate the square root of the maximum element and update it
            *max_it = static_cast<int>(sqrt(*max_it));
            count++;
        }

        // Calculate the sum of all elements
        for (int i = 0; i < gifts.size(); i++) {
            sum += gifts[i];
        }

        return sum;
    }
};