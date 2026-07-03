//leetcode 39.Combination sum

class Solution {
public:
    void solve(vector<int>& candidates,int target,int idx,vector<int>& output,vector<vector<int>>&answer){
        if(target == 0){
            answer.push_back(output);
            return;
        } 
        if(idx == candidates.size() || target < 0)
           return;

        output.push_back(candidates[idx]);
        solve(candidates,target - candidates[idx],idx,output,answer);
        output.pop_back();

        solve(candidates,target,idx + 1,output,answer);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>answer;
        vector<int>output;
        solve(candidates,target,0,output,answer);
        return answer;
    }
};
