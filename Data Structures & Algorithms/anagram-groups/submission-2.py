class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp=defaultdict(list)
        for x in strs:
            h=tuple(sorted(x))
            mp[h].append(x)
        return list(mp.values())