from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s = ""
        for i in range(len(digits)):
            s += str(digits[i])

        num = int(s) +1
        l2 = []
        while num > 0:
            ans = num % 10
            l2.append(ans)
            num = num // 10

        return l2[::-1]  
