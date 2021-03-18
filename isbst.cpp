bool isvalid = true;

int helper(TreeNode* root){
    if(!root)return 0;
    int lh = helper(root->left);
    int rh = helper(root->right);
    
    if(abs(lh-rh)>1)isvalid = false;
    return max(lh,rh)+1;
    
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        helper(root);
        return isvalid;
    }