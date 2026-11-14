class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp={}
        for x in nums:
            if x not in mp: mp[x]=1
            else: mp[x]+=1
        hp=[]
        for f,v in mp.items():
            heapq.heappush(hp,(-v,f))
        v=[]
        while(k):
            freq, num = heapq.heappop(hp)
            v.append(num)
            k-=1
        return v
        