class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: List[str]
        """
        l=s1.split()+s2.split()

        freq={}
        for word in l:
            if word in freq:
                freq[word]=freq[word]+1
            else:
                freq[word]=1    
        
        l2=[]
        for key in freq:
            if(freq[key]==1):
                l2.append(key)

        return l2            