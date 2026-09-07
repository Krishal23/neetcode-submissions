class Solution {
public:
    int rec(int i,int sum,vector<int>& nums, int target){
        if(i==nums.size()){
            if(sum==target)return 1;
            return 0;
        }
        int add=rec(i+1,sum+nums[i],nums,target);
        int sub=rec(i+1,sum-nums[i],nums,target);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(0,0,nums,target);
    }
};
