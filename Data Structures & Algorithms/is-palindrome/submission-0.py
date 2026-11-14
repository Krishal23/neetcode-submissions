class Solution:
    def isPalindrome(self, s: str) -> bool:
        t=""
        for x in s:
            if x.isalnum():
                t+=x
        t=t.lower()
        r=t[::-1]
        print(t)
        print(r)
        for i in range(len(t)):
            if(t[i]!=r[i]):return False
        return True