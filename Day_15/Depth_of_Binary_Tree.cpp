class Solution {
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int op1=0,op2=0,op3=0;
        if(root->right){
            op1 = diameterOfBinaryTree(root->right);
        }
        if(root->left){
            op2 = diameterOfBinaryTree(root->left);
        }
        op3 = height(root->left) + height(root->right);

        return max(op1,max(op2,op3));
    }
};