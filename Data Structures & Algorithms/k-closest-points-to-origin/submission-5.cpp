class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp=[](vector<int>a, vector<int>b){
            return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        };
        int n=points.size();
        priority_queue<vector<int>,vector<vector<int>>,decltype(comp)>pq(comp);
        for(vector<int>&e:points){
            pq.push(e);
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;

    }
};
