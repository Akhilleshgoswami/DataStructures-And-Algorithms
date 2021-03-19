class Solution {
public:
    Node* connect(Node* root) {
        Node* leftNode = root;
        while(leftNode!=nullptr and leftNode->left!=nullptr){
            populateLowerLEvel(leftNode);
            leftNode = leftNode->left;
        }
        return root;
    }
    void  populateLowerLEvel(Node* startNode){
        Node* iter = startNode;
        while(iter!=nullptr){
            iter ->left->next  =iter->right; 
            if(iter->next!=nullptr){
                iter->right->next = iter->next->left;
            }
            iter = iter ->next;
            
        }
        
    }
};
Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        std::deque<Node *>queue(1, root);
        while (!queue.empty()) {
            int count = queue.size();
            for (int i = 0; i < count; ) {
                Node *curQNode = queue.front();
                queue.pop_front();
                if (curQNode->left) {
                    queue.push_back(curQNode->left);
                    queue.push_back(curQNode->right);
                }
                if (++i < count)
                    curQNode->next = queue.front(); 
            }
        }
        return root;
    }