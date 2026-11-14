class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums : return 0
        nums.sort()
        p=nums[0]
        l=1
        ans=1
        # print(nums)
        for c in nums[1:]:
            if(c==p):continue;
            elif(c==p+1):
                l+=1
                ans=max(ans,l)
            else:
                l=1
            p=c
        return ans


        