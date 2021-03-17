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

// postorder
void print23 (Node* root){
	if(root){
		
		print23(root->left);
		
		print23(root->right);
		cout<<root->data<<" ";
	}
}

// postorder
void postorder(Node* root){

	stack<Node*>s;
	stack<int>ss;
	Node* temp;
	s.push(root);
	while(!s.empty()){
		 temp = s.top();
		s.pop();
		ss.push(temp->data);
		if(temp->left)s.push(temp->left);
		if(temp->right)s.push(temp->right);
	}
	while(!ss.empty()){
		cout<<ss.top()<<" ";
		ss.pop();
	}
}

int main(){
	Node* d = new Node(1);
	d->left = new Node(2);
	d->right = new Node(3);
	d->left->right = new Node(5);
	d->left->left = new Node(4);
   postorder(d);
   cout<<endl;
   print23(d);

		return 0;
	}