// Program to find ceil of a given value in BST 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has key, left child and right child */
class node { 
public: 
	int key; 
	node* left; 
	node* right; 
}; 

/* Helper function that allocates a new node with the given key and 
NULL left and right pointers.*/
node* newNode(int key) 
{ 
	node* Node = new node(); 
	Node->key = key; 
	Node->left = NULL; 
	Node->right = NULL; 
	return (Node); 
} 

// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 
int Ceil(node* root, int input) 
{ 
	// Base case 
	if (root == NULL) 
		return -1; 

	// We found equal key 
	if (root->key == input) 
		return root->key; 

	// If root's key is smaller, ceil must be in right subtree 
	if (root->key < input) 
		return Ceil(root->right, input); 

	// Else, either left subtree or root has the ceil value 
	int ceil = Ceil(root->left, input); 
	return (ceil >= input) ? ceil : root->key; 
} 

// Driver program to test above function 
int main() 
{ 
	node* root = newNode(8); 

	root->left = newNode(4); 
	root->right = newNode(12); 

	root->left->left = newNode(2); 
	root->left->right = newNode(6); 

	root->right->left = newNode(10); 
	root->right->right = newNode(14); 

	for (int i = 0; i < 16; i++) 
		cout << i << " " << Ceil(root, i) << endl; 

	return 0; 
} 

// This code is contributed by rathbhupendra 
// C++ program to find floor and ceil of a given key in BST 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has key, left child and right child */
struct Node { 
	int data; 
	Node *left, *right; 

	Node(int value) 
	{ 
		data = value; 
		left = right = NULL; 
	} 
}; 

// Helper function to find floor and ceil of a given key in BST 
void floorCeilBSTHelper(Node* root, int key, int& floor, int& ceil) 
{ 

	while (root) { 

		if (root->data == key) { 
			ceil = root->data; 
			floor = root->data; 
			return; 
		} 

		if (key > root->data) { 
			floor = root->data; 
			root = root->right; 
		} 
		else { 
			ceil = root->data; 
			root = root->left; 
		} 
	} 
	return; 
} 

// Display the floor and ceil of a given key in BST. 
// If key is less than the min key in BST, floor will be -1; 
// If key is more than the max key in BST, ceil will be -1; 
void floorCeilBST(Node* root, int key) 
{ 

	// Variables 'floor' and 'ceil' are passed by reference 
	int floor = -1, ceil = -1; 

	floorCeilBSTHelper(root, key, floor, ceil); 

	cout << key << ' ' << floor << ' ' << ceil << '\n'; 
} 

// Driver program to test above function 
int main() 
{ 
	Node* root = new Node(8); 

	root->left = new Node(4); 
	root->right = new Node(12); 

	root->left->left = new Node(2); 
	root->left->right = new Node(6); 

	root->right->left = new Node(10); 
	root->right->right = new Node(14); 

	for (int i = 0; i < 16; i++) 
		floorCeilBST(root, i); 

	return 0; 
} 
