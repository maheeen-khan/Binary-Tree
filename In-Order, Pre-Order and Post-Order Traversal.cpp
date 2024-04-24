// Binary Search Tree. 
//Perform In-Order,Pre-Order,and Post-Order Traversal

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

//In-Order Traversal
void inOrder(BstNode* root){
	if(root == NULL){
		return;
	}
	inOrder(root -> left);
	cout<< root -> data <<" ";
	inOrder(root -> right);
}

//Pre-Order Traversal
void preOrder(BstNode* root){
	if(root == NULL){
		return;	
	}
	cout<< root -> data<<" ";
	preOrder(root -> left);
	preOrder(root -> right);
}

//Post-Order Traversal
void postOrder(BstNode* root){
	if(root == NULL){
		return;
	}
	postOrder(root -> left);
	postOrder(root -> right);
	cout<< root -> data<<" ";
}
int main() {
	
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	
	cout<<"In-Order Traversal : ";
	inOrder(root);
	 
	cout<<"\n";
	
	cout<<"Pre-Order Traversal : ";
	preOrder(root);
	
	cout<<"\n";
	
	cout<<"Post-Order Traversal : ";
	postOrder(root);
}
