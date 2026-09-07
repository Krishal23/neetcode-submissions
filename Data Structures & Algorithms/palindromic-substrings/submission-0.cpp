class Solution {
public:
    bool isPalindrome(string s){
        string rev=s;
        reverse(rev.begin(),rev.end());
        return rev==s;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s.substr(i,j-i+1)))cnt++;
            }
        }
        return cnt;
        
    }
};
