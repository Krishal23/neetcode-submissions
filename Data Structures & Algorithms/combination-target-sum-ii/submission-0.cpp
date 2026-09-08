class Solution {
public:
    void rec(int ind,vector<int>&nums, int k, vector<int>&curr, vector<vector<int>>&ans){
        if(k<0)return ;
        if(k==0){
            ans.push_back(curr);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            if(nums[i]>k)break;
            curr.push_back(nums[i]);
            rec(i+1,nums,k-nums[i],curr,ans);
            curr.pop_back();
        }
            
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        rec(0,nums,target,curr,ans);
        return ans;
    }
};
