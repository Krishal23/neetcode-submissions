class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int e:nums){
            if(pq.size()>=k){
                if(pq.top()<e){
                    pq.pop();
                    pq.push(e);
                }
            }else pq.push(e);
        }
        // cout<<pq.size()<<pq.top();
        // while(pq.size()>1){
        //     cout<<endl<<pq.top()<<endl;
        //     pq.pop();
        // }
        return pq.top();
// 2 3 
    }
};
