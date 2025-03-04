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
            int powVal = pow(3, x);
            if (powVal <= n) {
                n -= powVal;
                res.push_back(x);
            }
            x--;
        }

        
        return (n == 0);
    }
};
