
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sortedList = sorted((nums))
        for i in range(len(sortedList)):
            if(sortedList[i] != i):
                return i
            elif(i == (len(sortedList)-1)):
                return len(sortedList)
            else:
                continue

            
                