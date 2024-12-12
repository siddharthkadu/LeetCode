class Solution {
public:
    

    vector<int> countBits(int n) {
        vector<int> arr(n+1);

        for(int i=0;i<arr.size();i++){
          bitset<32> binary(i);
          arr[i]=binary.count();

        }
        return arr;
        
    }
};