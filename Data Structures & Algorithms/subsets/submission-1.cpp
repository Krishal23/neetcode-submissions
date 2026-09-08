class Solution {
public:
    void rec(int i,vector<int>&nums, vector<int>&curr, vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        rec(i+1,nums,curr,ans);
        curr.push_back(nums[i]);
        rec(i+1,nums,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans={{}};
        for(int num:nums){
            int sz=ans.size();
            for(int i=0;i<sz;i++){
                vector<int>curr=ans[i];
                curr.push_back(num);
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
