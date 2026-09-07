class Solution {
public:
    int rec(int i,int sum,vector<int>& nums, int target,vector<vector<int>>&dp,int offset){
        if(i==nums.size()){
            if(sum==target)return 1;
            return 0;
        }
        if(dp[i][sum+offset]!=-1)return dp[i][sum+offset];
        int add=rec(i+1,sum+nums[i],nums,target,dp,offset);
        int sub=rec(i+1,sum-nums[i],nums,target,dp,offset);
        return dp[i][sum+offset]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size(),vector<int>(2*totSum+1,-1));
        return rec(0,0,nums,target,dp,totSum);
    }
};
