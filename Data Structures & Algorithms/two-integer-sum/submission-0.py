class Solution:
    def twoSum(self, nums: List[int], t: int) -> List[int]:
        mp={}
        for i,x in enumerate(nums):
            if(t-x in mp):
                return [mp[t-x],i]
            mp[x]=i
        return []