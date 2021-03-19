class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (root == NULL) {
            return NULL;
        }
        
        if (root == p or root == q) {
            return root;
        }
        
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        
        if (leftAns and !rightAns) {
            return leftAns;
        }
        
        if (rightAns and !leftAns) {
            return rightAns;
        }
        
        if (leftAns and rightAns) {
            return root;
        }
        return NULL;
    }
    
};

