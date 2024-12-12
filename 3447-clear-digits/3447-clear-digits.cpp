
    
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st; // To track non-digit characters
        for (char ch : s) {
            if (isdigit(ch)) {
                // If the current character is a digit, remove the closest non-digit from the stack
                if (!st.empty()) {
                    st.pop(); // Remove the closest non-digit
                }
            } else {
                // If the character is not a digit, add it to the stack
                st.push(ch);
            }
        }

        // Construct the result string from the stack
        string result = "";
        while (!st.empty()) {
            result += st.top();            
            st.pop();
        }
        reverse(result.begin(), result.end()); // Reverse to get the correct order
        return result;
    }
};
