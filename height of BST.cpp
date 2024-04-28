// Binary Search Tree. 
//Perform Height and Level order Traversal.

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<queue>
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


//Pre-Order Traversal
void preOrder(BstNode* root){
	if(root == NULL){
		return;	
	}
	cout<< root -> data<<" ";
	preOrder(root -> left);
	preOrder(root -> right);
}

//Height of Tree / Maximum Depth of a Tree 

int height(BstNode* root){
	if(root == NULL){
		return -1;
	}
	int height_of_root_right = height(root -> right);
	int height_of_root_left = height(root -> left);
	
	return max(height_of_root_right,height_of_root_left)+1;
}

//Level Order Traversal
void levelOrderTraversal(BstNode* root){
	if(root == NULL){
		return;	
	}
	
	queue<BstNode*> q;
	q.push(root);
	
	while(!q.empty()){
		BstNode* current = q.front();
		cout<<current -> data<<" ";
		if(current -> left != NULL) q.push(current -> left);
		if(current -> right != NULL) q.push(current -> right);
		q.pop();
	}
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
	
	cout<< "Height of BST : "<<height(root);
	
	cout<<"\nPre-Order Traversal : ";
	preOrder(root);
	
	cout<<"\n";

	levelOrderTraversal(root);
}
