class Solution {
    
    void help(TreeNode* root, int low, int high, int& sum){
        if(root == NULL){
            return;
        }

        if(root->val >= low && root->val <= high){
            sum += root->val;
        }

        help(root->left, low,high, sum);
        help(root->right, low, high, sum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        help(root,low,high,sum);
        return sum;
    }
};