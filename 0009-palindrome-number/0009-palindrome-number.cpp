class Solution {
public:
    bool isPalindrome(int x) {
      
      
        string str=to_string(x);
        
        string str2=str;
        int i=0;
        int j=str2.size()-1;
        while(i<j){
            swap(str2[i],str2[j]);
            i++;
            j--;
        }
        if(str2==str) {return true;}
        else {return false;}
    }
};