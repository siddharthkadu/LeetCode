class Solution {
public:
   int minimizeXor(int num1, int num2) {
    int setBits = __builtin_popcount(num2);  // Count set bits in num2
    int result = 0;

    // Step 1: Set bits in num1's positions
    for (int i = 31; i >= 0 && setBits > 0; i--) {
        if (num1 & (1 << i)) {
            result |= (1 << i);
            setBits--;
        }
    }

    // Step 2: Fill remaining bits from LSB
    for (int i = 0; i <= 31 && setBits > 0; i++) {
        if ((result & (1 << i)) == 0) {
            result |= (1 << i);
            setBits--;
        }
    }

    return result;
}

};


