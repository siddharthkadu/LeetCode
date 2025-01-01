class Solution {
public:


  //It is beeter approch than previous i have solve 
    int maxScore(string s) {


        int total_one=0;
        int zero=0;
        int one=0;
        int res=0;
        int n=s.size();
    // count no of zero's and no of one's simultenously 

        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                total_one++;
            }
        }

       


        for(int i=0;i<=n-2;i++){
            if(s[i]=='0'){
                zero++;
            }
            
            if(s[i]=='1'){
                one++;
            }

         res=max(res,(zero+(total_one-one)));

        }
        
        

            
return res;
        
        
    }
};