#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int value){
		data = value;
		left = nullptr;
		right = nullptr;
	}
};
//preorder
void print (Node* root){
	if(root){
		cout<<root->data<<" ";
		print(root->left);
		print(root->right);
	}
}
//inoreder
void print2 (Node* root){
	if(root){
		
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}
}
// postorder
void print23 (Node* root){
	if(root){
		
		print(root->left);
		
		print(root->right);
		cout<<root->data<<" ";
	}
}
void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
 
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
 
    } /* end of while */
}
// postorder
void postorder(Node* root){
	stack<Node*>s;
	while(root != NULL || s.empty() == false){
		while(root){
			cout<<root->data<<" ";
			s.push(root);
			root = root->left;
		}
		if(s.empty()){
break;
		}
	root = s.top();
	s.pop();
	root = root->right;
	}
}
int main(){
	Node* d = new Node(1);
	d->left = new Node(2);
	d->right = new Node(3);
	d->left->right = new Node(4);
	d->left->left = new Node(5);
   postorder(d);

		return 0;
	}