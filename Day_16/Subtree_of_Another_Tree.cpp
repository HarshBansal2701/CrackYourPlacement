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
    bool check(TreeNode* r1, TreeNode* r2){
        if(r1 ==NULL || r2==NULL){
            return r1==r2;
        }
        if(r1->val != r2->val){
            return false;
        }
        bool left = check(r1->left , r2->left);
        bool right = check(r1->right , r2->right);

        return left&&right;
    }


    void findNode(TreeNode* root, TreeNode* subRoot, bool& ans){
        if(root == NULL){
            return ;
        }
        findNode(root->left, subRoot , ans);
        if(root->val == subRoot->val){
            ans = ans || check(root , subRoot);
        }
        findNode(root->right, subRoot , ans);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;

        findNode(root,subRoot, ans);

        return ans;
    }
};