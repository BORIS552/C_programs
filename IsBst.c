#include<stdio.h>
#include<stdlib.h>

struct BSTNode {
	int data;
	struct node *left;
	struct node *right;
};

int isBstHelper(struct BSTNode *node,int min, int max) {
	//empty tree is always a BST
	if(node == NULL)
		return 1;
	if(node->data < min || node->data > max)
		return 0;
	return isBstHelper((struct BSTNode *)node->left,min, node->data-1) && isBstHelper((struct BSTNode*)node->right,node->data+1,max);

}

int isBst(struct BSTNode* node) {
	return isBstHelper(node,-999,999);
}

// method for creating the node 
struct BSTNode* newNode(int data) {
	struct BSTNode *node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int main() {
	struct BSTNode *root;
	int ch =1;
	switch(ch) {
		case 0:
				root = newNode(1);
				struct BSTNode *r = (struct BSTNode*)malloc(sizeof(struct BSTNode));
				r->data = 3;
				root->right= r;
				struct BSTNode *l = (struct BSTNode*)malloc(sizeof(struct BSTNode));
				l->data = -3;
				root->left = l;
				struct BSTNode *l1 = (struct BSTNode*)malloc(sizeof(struct BSTNode));
				l1->data = -6;
				l->left = l1;
				break;
		case 1:
				root = newNode(1);
				struct BSTNode *r = newNode(-2);
				root->right= r;
				struct BSTNode *l = newNode(-3);
				root->left = l;
				struct BSTNode *l1 = newNode(-6);
				l->left = l1;
				break;
						
	}

	if(isBst(root)) printf("true");
	else printf("false");
	return 0;
}

