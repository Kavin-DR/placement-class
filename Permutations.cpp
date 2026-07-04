//leetcode 46. Permutations

class Solution {
public:
    void solve(vector<int>& nums,int idx,vector<vector<int>>& answer)
    {
        if(idx == nums.size())
        {
            answer.push_back(nums);
            return;
        }
        for(int i = idx;i < nums.size();i++)
        {
            swap(nums[idx],nums[i]);

            solve(nums,idx + 1,answer);

            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {  
        vector<vector<int>>answer;
        solve(nums,0,answer);
        return answer;           
        }
    }
};
