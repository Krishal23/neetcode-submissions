class Solution {
public:
    double dist(int x, int y){
        return abs(x)+abs(y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        for(vector<int>e:points){

            pq.push({dist(e[0],e[1]),e});
        }
        vector<vector<int>>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};
