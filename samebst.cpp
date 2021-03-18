class Solution {
public:
    
        bool isSameTree(TreeNode* p, TreeNode* q) {
        deque<pair<TreeNode*,TreeNode*>> dq;
        dq.push_back({p,q});
        while(!dq.empty())
        {
            pair p1(dq.front());
            dq.pop_front();
            if(p1.first==NULL && p1.second== NULL)   continue;
            if((p1.first==NULL || p1.second==NULL) || (p1.first->val!=p1.second->val))  return false;
            dq.push_back({p1.first->left,p1.second->left});
            dq.push_back({p1.first->right,p1.second->right});
        }
        return true;
        }
    
};