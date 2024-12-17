class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Step 1: Count the frequency of each character
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Step 2: Create a max heap (priority queue) to store characters and their frequencies
    priority_queue<pair<char, int>> maxHeap;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            maxHeap.push({(char)('a' + i), freq[i]});
        }
    }

    string result = "";
    while (!maxHeap.empty()) {
        // Step 3: Pick the lexicographically largest character
        auto [currentChar, currentFreq] = maxHeap.top();
        maxHeap.pop();

        // Determine how many times we can add the character without violating the repeatLimit
        int timesToAdd = min(currentFreq, repeatLimit);

        // Add the character to the result string
        for (int i = 0; i < timesToAdd; i++) {
            result += currentChar;
        }

        // Update the remaining frequency
        currentFreq -= timesToAdd;

        // Step 4: If there's still frequency left for this character
        if (currentFreq > 0) {
            if (maxHeap.empty()) {
                // If there is no other character to break the sequence, stop
                break;
            }

            // Step 5: Use the second-largest character to break the repeat sequence
            auto [nextChar, nextFreq] = maxHeap.top();
            maxHeap.pop();

            result += nextChar; // Add the second-largest character once
            nextFreq--;

            // Push the updated second-largest character back into the heap
            if (nextFreq > 0) {
                maxHeap.push({nextChar, nextFreq});
            }

            // Push the current character back into the heap for future use
            maxHeap.push({currentChar, currentFreq});
        }
    }

    return result;
        
    }
};