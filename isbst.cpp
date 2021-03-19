class Solution {
public:
bool isValidBST(TreeNode* node, 
    TreeNode *minNode=NULL, TreeNode *maxNode=NULL) {

        // Empty Tree || Leaf Nodes => Valid BST
    if(!node) return true;

        // Node not satisfying BST rule
    if((minNode && node->val <= minNode->val) || 
       (maxNode && node->val >= maxNode->val))	
        return false;

        // Recursively check left and right sub trees
    bool isLeftBST = isValidBST(node->left,minNode,node);
    bool isRightBST = isValidBST(node->right,node,maxNode);

    return isLeftBST && isRightBST;

}

};