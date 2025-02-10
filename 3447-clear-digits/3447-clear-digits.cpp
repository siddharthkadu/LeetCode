class Solution {
public:
    string clearDigits(string s) {
       stack<char> st;

    for (char c : s) {
        if (isdigit(c)) {  
            // Remove the closest non-digit character if the stack is not empty
            if (!st.empty() && !isdigit(st.top())) {
                st.pop();
            }
        } else {
            st.push(c);  // Push non-digit characters
        }
    }

    // Construct the resulting string from the stack
    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}
    
};    


