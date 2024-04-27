// Binary Search Tree. 
//Implement Deletion Algorithms in BST.
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

//Deleting function

BstNode* deletion(BstNode* root, int toDel){
	
	if(root == NULL){
		cout<<"Tree is empty!";
		return NULL;
	}
	
	else if(root -> data < toDel){
		root -> right =	deletion(root -> right, toDel);
	}
	
	else if(root -> data > toDel){
		root -> left =	deletion(root -> left, toDel);
	}
	
	else{
		//Now! I found that value which is going to be delete.
		
		//Case 1 : having No child
		if(root -> right == NULL && root -> left == NULL){
			delete root;
			root = NULL;
			return root; //root is a dangling pointer bcoz object in heap is deleted But root still has its address. That's why we set root as NULL
		}
		
		//Case 2 : having 1 child
		else if (root -> right == NULL){
			BstNode* temp = root;
			root = root -> left;
			delete temp;
			return root;
		}
			
		else if (root -> left == NULL){
			BstNode* temp = root;
			root = root -> right;
			delete temp;
			return root;
		}
		
		//Case 3 : having 2 children
		else{
			int temp = minimum(root -> right);
			root -> data = temp;
			root -> right = deletion(root -> right,temp);
			return root;		
			}
		}
	
}

//Pre order Traversal
void preOrder(BstNode* root){
	if(root == NULL){
		return;	
	}
	cout<< root -> data<<" ";
	preOrder(root -> left);
	preOrder(root -> right);
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
	
	preOrder(root);
	
	cout <<"\n";
	
	deletion(root, 15);
	
	preOrder(root);

	 
}
