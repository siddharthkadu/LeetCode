class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk=0;
        int MaxSoFar=0;

        for(int i=0;i<arr.size();i++){
            MaxSoFar=max(MaxSoFar,arr[i]);
            if(MaxSoFar==i){
                chunk++;
            }
        }
        return chunk;
    }
};