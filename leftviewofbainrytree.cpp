#include <bits/stdc++.h> 
  
using namespace std; 
  
// A Binary Tree Node 
struct node { 
    int data; 
    struct node *left, *right; 
}; 
  
// A utility function to create a new 
// Binary Tree node 
struct node* newNode(int item) 
{ 
    struct node* temp = new node; 
    temp->data = item; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
  
// Utility function to print the left view of 
// the binary tree 
void leftViewUtil(struct node* root, queue<node*>& q) 
{ 
    if (root == NULL) 
        return; 
  
    // Push root 
    q.push(root); 
  
    // Delimiter 
    q.push(NULL); 
  
    while (!q.empty()) { 
        node* temp = q.front(); 
  
        if (temp) { 
  
            // Prints first node 
            // of each level 
            cout << temp->data << " "; 
  
            // Push children of all nodes at 
            // current level 
            while (q.front() != NULL) { 
  
                // If left child is present 
                // push into queue 
                if (temp->left) 
                    q.push(temp->left); 
  
                // If right child is present 
                // push into queue 
                if (temp->right) 
                    q.push(temp->right); 
  
                // Pop the current node 
                q.pop(); 
  
                temp = q.front(); 
            } 
  
            // Push delimiter 
            // for the next level 
            q.push(NULL); 
        } 
  
        // Pop the delimiter of 
        // the previous level 
        q.pop(); 
    } 
} 

  void topview( struct node* root){
    if(!root)return;
    queue<pair< struct node*,int>>q;
    map<int,int>map;
    q.push({root,0});
    while(!q.empty()){
        pair< struct node*,int>cur = q.front();
        q.pop();
        if(map.find(cur.second)==map.end()){
            map[cur.second] = cur.first->data;
        }
         if(cur.first->left)
        q.push(make_pair(cur.first->left,cur.second-1));
        if(cur.first->right)
        q.push(make_pair(cur.first->right,cur.second+1));
    }
    for(auto i : map)cout<<i.second<<" ";
}






  void left(struct node* root){
    std::vector<int> view;
        if(!root)return ;
        queue<struct node*>q;
        view.push_back(root->data);
        vector<int>count;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
struct node* curr = q.front();
            q.pop();
            if(!curr){
                if(count.size()){
                    view.push_back(count.back());
                }q.push(nullptr);
                count.clear();
                if(q.front() == nullptr)break;
                continue;
            }
        if(curr->right){
    q.push(curr->right);
     count.push_back(curr->right->data);  
        }
        if(curr->left){
q.push(curr->left);
      count.push_back(curr->left->data);  
        }
               
        
        }
        for(auto i:view)cout<<i<<" ";
  }
// Function to print the leftView 
// of Binary Tree 
void leftView(struct node* root) 
{ 
    // Queue to store all 
    // the nodes of the tree 
    queue<node*> q; 
  
    leftViewUtil(root, q); 
} 
  
// Driver Code 
int main() 
{ 
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->left->left = newNode(5); 
    // root->right->left->right = newNode(6); 
    // root->right->left->right->left = newNode(18); 
    // root->right->left->right->right = newNode(7); 
  
    // leftView(root); 
    // cout<<endl;
    // left(root);
    //   cout<<endl;
      topview(root);
  
    return 0; 
} 