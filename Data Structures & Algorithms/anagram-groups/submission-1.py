class Solution:
    def hash(self,s):
        v=[0]*26
        for x in s:
            v[ord(x)-ord('a')]+=1
        return tuple(v)

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp=defaultdict(list)
        for x in strs:
            h=self.hash(x)
            mp[h].append(x)
        return list(mp.values())