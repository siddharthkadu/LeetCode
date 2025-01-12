class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        
        // If the length is odd, it's impossible to form a valid parentheses string
        if (n % 2 != 0) return false;

        // Left-to-right pass: check for excessive ')'
        int balance = 0, flexible = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                balance += (s[i] == '(') ? 1 : -1;
            } else {
                flexible++;  // Can be '(' or ')'
            }

            // Too many ')' without enough '(' or flexible spots to balance
            if (balance + flexible < 0) return false;
        }

        // Right-to-left pass: check for excessive '('
        balance = 0, flexible = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                balance += (s[i] == ')') ? 1 : -1;
            } else {
                flexible++;
            }

            // Too many '(' without enough ')' or flexible spots to balance
            if (balance + flexible < 0) return false;
        }

        return true;
    }
};
