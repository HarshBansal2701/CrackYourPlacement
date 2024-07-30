/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* help(vector<int>& nums,int j,int i){
        if(i>j){
            return NULL;
        }
        int mid = (j-i)/2+i;

        TreeNode* node = new TreeNode(nums[mid]);
        if(i==j){
            return node;
        }
        node->left = help(nums,mid-1,i);
        node->right = help(nums,j,mid+1);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = help(nums, nums.size()-1 ,0);
        return root;
    }
};