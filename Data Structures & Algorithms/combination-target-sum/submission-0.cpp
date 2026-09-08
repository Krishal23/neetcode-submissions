class Solution {
public:
    void rec(int i,vector<int>&nums, int k, vector<int>&curr, vector<vector<int>>&ans){
        if(k<0)return ;
        if(k==0){
            ans.push_back(curr);
            return;
        }
        if(i==nums.size()){
            return;
        }
        curr.push_back(nums[i]);
        rec(i,nums,k-nums[i],curr,ans);
        curr.pop_back();
        rec(i+1, nums,k, curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        rec(0,nums,target,curr,ans);
        return ans;
    }
};