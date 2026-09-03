class Solution(object):
    def findKthPositive(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        j =0
        for i in range(1,max(arr)+2+k):
            if(j==k):
                return i-1
            if(i in arr):
                continue
            else:
                j = j+1
            



        