class Solution {
public:
    void solve(vector<int>& candidates,int target,int idx,vector<int>& output,vector<vector<int>>&answer){

        if(target == 0)
        {
            answer.push_back(output);
            return;
        }

        if(target < 0 || idx >= candidates.size())
           return;
           
        for(int i = idx;i < candidates.size();i++)
        {
            if(i > idx && candidates[i] == candidates[i - 1])
            continue;

            output.push_back(candidates[i]);
            solve(candidates,target - candidates[i],i + 1,output,answer);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> answer;
        vector<int>output;
        solve(candidates,target,0,output,answer);
        return answer;
    }
};
