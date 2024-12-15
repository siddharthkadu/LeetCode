class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
         int max_time = 0;         // Tracks the longest press time
        int max_button = -1;      // Tracks the index of the button with the longest press time
        int prev_time = 0;        // Previous event time, initialized to 0

        for (const auto& event : events) {
            int index = event[0];
            int time = event[1];

            // Calculate the time taken to press the current button
            int press_time = time - prev_time;

            // Update the longest press time and button index
            if (press_time > max_time || (press_time == max_time && index < max_button)) {
                max_time = press_time;
                max_button = index;
            }

            // Update the previous time to the current event's time
            prev_time = time;
        }

        return max_button;
    }
};