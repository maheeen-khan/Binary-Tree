// Binary Search Tree. 
//Implement Insertion and Searching Algorithms.
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

//Find minimum function

int minimum(BstNode* root){
	
	if(root == NULL){
		cout<<"Tree is empty";
		return -1;
	}
	else if(root -> left == NULL){
		return root -> data;
	}
	return minimum(root -> left);
}

//Find Maximum function

int maximum(BstNode* root){
	
	if(root == NULL){
		cout<<"Tree is empty";
		return -1;
	}
	else if(root -> right == NULL){
		return root -> data;
	}
	return maximum(root -> right);
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
	
	cout<< minimum(root);
	cout<<"\n";
	cout<< maximum(root);
	 
}
