class Solution:
    def isPalindrome(self, s: str) -> bool:
        #remove space's and coma's
        #join them 
        #then reverse it

        s1=""
        for i in range(0,len(s)):
            if(s[i]>='A' and s[i]<='Z'):
                s1=s1+chr(ord(s[i])+32)
            else:
                s1=s1+s[i]  
        s2=''        

        for i in range(0,len(s1)):
            if((ord(s1[i])>=97 and ord(s1[i])<=122) or (ord(s1[i])>=48 and ord(s1[i])<=57)) :
                s2=s2+s1[i]

         
        s3=s2[::-1]
        if(s2==s3):
            return True
        else:
            return False    