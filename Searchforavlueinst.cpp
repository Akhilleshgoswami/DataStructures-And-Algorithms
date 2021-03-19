 // Recursive Solution
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || val == root->val)
            return root;
        if (val < root->val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
    
    // Iterative Solution
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val)
            root = (val < root->val)?root->left:root->right;
        return root;
    }
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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *curr = root;
        while(curr)
        {
            if(curr->val==val)
                return curr;
            else if(curr->val>val)
                curr=curr->left;
            else
                curr=curr->right;
        }
        return curr;
    }
};