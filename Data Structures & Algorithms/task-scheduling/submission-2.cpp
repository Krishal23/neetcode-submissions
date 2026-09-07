class Solution {
public:
    int leastInterval(vector<char>& tasks, int cd) {
        int n=tasks.size();
        int t=0;
        vector<int>frq(26,0);
        for(char e:tasks){
            frq[e-'A']++;
        }
        priority_queue<pair<int,int>>active;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>cool;
        for(int i=0;i<26;i++){
            if(frq[i]>0)active.push({frq[i],i});
        }
        while(!active.empty() || !cool.empty()){
            if(active.empty()){
                t=max(t,cool.top().first);
            }
            while(!cool.empty() && t>=cool.top().first){
                int tsku=cool.top().second;
                cool.pop();
                active.push({frq[tsku],tsku});
            }
            if(!active.empty()){
                int tsk=active.top().second;
                active.pop();
                frq[tsk]--;
                if(frq[tsk]>0){
                    cool.push({t+cd+1,tsk});
                }
            }
            t++;
        }
        
        return t;

    }
};
