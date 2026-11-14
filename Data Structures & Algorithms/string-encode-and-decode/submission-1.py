class Solution:
    def wrdenc(self,x):
        s="."
        for c in x:
            s=s+str(ord(c))+"."
        return s

    def encode(self, strs: List[str]) -> str:
        s="#"
        for x in strs:
            t=self.wrdenc(x)
            s=s+t+"#"
        return s

    def decode(self, s: str) -> List[str]:
        l=s[1:-1].split('#')
        i=1
        j=1
        print(l)
        ans=[]
        for x in l:
            if not x: break
            t=x[1:-1].split('.')
            s=""
            for w in t:
                if w=="": break
                s+= (chr(int(w)))
            print(s)
            ans.append(s)
        return ans