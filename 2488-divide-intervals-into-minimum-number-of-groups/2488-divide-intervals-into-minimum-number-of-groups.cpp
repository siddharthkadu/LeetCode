
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> events;
        
        // Record start and end times
        for (const auto& interval : intervals) {
            events[interval[0]]++;         // Start of an interval
            events[interval[1] + 1]--;     // End of an interval (right + 1)
        }
        
        int maxGroups = 0, currentGroups = 0;
        
        // Traverse the event map to calculate the maximum overlap
        for (auto& event : events) {
            currentGroups += event.second; // Update active intervals count
            maxGroups = max(maxGroups, currentGroups); // Track maximum overlap
        }
        
        return maxGroups; // The minimum number of groups needed
    }
};
