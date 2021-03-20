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

//inoreder
void print2 (Node* root){
	if(root){
		
		print2(root->left);
		cout<<root->data<<" ";
		print2(root->right);
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

int main(){
	Node* d = new Node(3);
	d->left = new Node(5);
	d->right = new Node(1);
  d->right->left = new Node(0);
  d->right->right = new Node(8);
	d->left->right = new Node(5);
    d->left->right->right = new Node(2);
      // d->left->right->right = new Node(4);
        d->left->right->left = new Node(7);
	d->left->left = new Node(6);
  inOrder(d);
  cout<<endl;
  print2(d);

		return 0;
	}