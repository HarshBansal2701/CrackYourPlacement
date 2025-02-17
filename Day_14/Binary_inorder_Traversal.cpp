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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        stack<TreeNode*> s;
        vector<int> ans;

        while(root || s.size()){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                TreeNode* temp = s.top();
                s.pop();
                ans.push_back(temp->val);
                if(temp->right){
                    root = temp->right;
                }
            }
        }
        return ans;
    }
};