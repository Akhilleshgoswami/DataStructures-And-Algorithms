class Solution {
public:
	// consider that we need to iterate all nodes in the left subtree before building the right one,
	// so we can use a simple index to iterate the elements in preorder
    int preIdx = 0;
    unordered_map<int, int> inorderMap;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
			inorderMap.emplace(inorder[i], i);
		return buildTreeWithMap(preorder, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeWithMap(vector<int>& preorder, vector<int>& inorder, int start, int end)     {
		if (start > end) return nullptr;
		TreeNode* node = new TreeNode(preorder[preIdx++]);
		int inIdx = inorderMap[node->val];
		node->left = buildTreeWithMap(preorder, inorder, start, inIdx - 1);
		node->right = buildTreeWithMap(preorder, inorder, inIdx + 1, end);
		return node;
	}
};

