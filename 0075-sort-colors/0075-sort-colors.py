class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        l2=[]
        c_0=0
        c_1=0
        c_2=0
        for i in range(len(nums)):
            if(nums[i]==0):
                c_0=c_0+1
            elif(nums[i]==1):
                c_1=c_1+1
            else:
                c_2=c_2+1


        d={0:c_0,1:c_1,2:c_2}
  

        for key in d:
            count = d[key]
            for _ in range(count):
                l2.append(key)


        for i in range(len(nums)):
            nums[i]=l2[i]          