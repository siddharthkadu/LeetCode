class Solution {
public:
    bool isValid(string s) {

        stack<char>st;
        unordered_map<char, char> matchingBrackets = {
        {')', '('},  // Closing parentheses maps to opening
        {']', '['},  // Closing square brackets map to opening
        {'}', '{'}   // Closing curly braces map to opening
    };

    for(char  ch:s){
        if(ch=='('||ch=='{'||ch=='['){
            st.push(ch);
        }
        else if(ch==')' || ch=='}' || ch==']'){
            if(st.empty() || st.top()!=matchingBrackets[ch]){
                return false;

            }
            st.pop();
        }
    }
        return st.empty();
    }
};