class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        p=[1]*len(nums)
        n=[1]*len(nums)
        p[0]=nums[0]
        n[len(nums)-1]=nums[-1]
        for i in range(1, len(nums)):
            p[i]=nums[i]*p[i-1]
            n[-i-1]=nums[-i-1]*n[-i]
        ans=[1]*len(nums)
        ans[0]=n[1]
        ans[-1]=p[-2]
        for i in range(1,len(nums)-1):
            ans[i]=n[i+1]*p[i-1]
        # print(n)
        # print(p)
        return ans
