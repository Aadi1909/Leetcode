class Solution(object):
    def findErrorNums(self, nums):
        answer = []
        nums.sort()
        n = len(nums)
        dup = 0
        array_sum = sum(nums)
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                answer.append(nums[i])
                dup = nums[i]

        total_sum = (n*(n+1)/2) - array_sum + dup
        answer.append(total_sum)
        return answer
