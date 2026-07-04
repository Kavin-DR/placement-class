//leetcode 47. Permutations II

class Solution {
public:
    void sam(vector<int>& nums,int index,vector<vector<int>>& answer)
    {
        if(index == nums.size())
        {
            answer.push_back(nums);
            return;
        }
        unordered_set<int> used;

        for(int i = index;i < nums.size();i++){
            if(used.count(nums[i]))
               continue;
            used.insert(nums[i]);
            swap(nums[index],nums[i]);
            sam(nums,index + 1,answer);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>answer;
        sam(nums,0,answer);
        return answer;
        }
};
