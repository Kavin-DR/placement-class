//leetcode 108. Convert Sorted Array to Binary Search Tree

class Solution {
public:
TreeNode* build(vector<int>& nums,int lft,int ryt)
{
    if(lft > ryt)return nullptr;
        int mid = lft + (ryt - lft) / 2;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums,lft,mid - 1);
    root->right = build(nums,mid + 1,ryt);

    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return build(nums, 0, nums.size() - 1);
    }
};
