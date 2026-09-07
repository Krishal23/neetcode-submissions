class Solution {
public:
    int leastInterval(vector<char>& tasks, int cd) {
        int n=tasks.size();
        int mxFrq=0;
        vector<int>frq(26,0);
        for(char e:tasks){
            frq[e-'A']++;
            mxFrq=max(mxFrq,frq[e-'A']);
        }
        int cnt=0;
        for(int f:frq){
            if(f==mxFrq)cnt++;
        }
        
        int ans=(mxFrq-1)*(cd+1) + cnt;
        return max(n,ans);

    }
};
