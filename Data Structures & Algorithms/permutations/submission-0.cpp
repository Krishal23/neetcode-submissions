class Solution {
public:
    void rec(int idx, vector<int>&nums, vector<int>&curr, vector<vector<int>>& ans){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!(idx & (1<<i))){
                curr.push_back(nums[i]);
                rec(idx | (1<<i) , nums,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        rec(0,nums,curr,ans);
        return ans;
    }
};
