class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res;
       
        for(int i=0;i<boxes.size();i++){
             int sum=0;
            for(int j=0;j<boxes.size();j++){
                if(boxes[j]=='1'){
                    sum=sum+abs(i-j);
                }
               
            }
             res.push_back(sum);
        }
        
        return res;
    }
};

