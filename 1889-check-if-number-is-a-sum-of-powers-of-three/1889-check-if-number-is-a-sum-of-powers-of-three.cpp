class Solution {
public:
    bool checkPowersOfThree(int n) {

        int x;
        vector<int> res;

        
        for (int i = 15; i >= 0; i--) {  
            if (pow(3, i) <= n) {
                x = i;
                break;
            }
        }

      
        while (x >= 0) {
            int pow_val = pow(3, x);
            if (pow_val <= n) {
                n =n-pow_val;
                res.push_back(x);
            }
            x--;
        }

        
        return (n == 0);
    }
};
