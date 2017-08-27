#include <stdio.h>
#include <stdlib.h>

struct BTNode {
	int data;
	struct BTNode *left;
	struct BTNode *right;
};



int CheckSymmetric(const struct BTNode *subTree0, const struct BTNode *subTree1) {

	  if (subTree0 == NULL && subTree1 == NULL) {
	     return 1;
	  } else if (subTree0 != NULL && subTree1 != NULL) {
	      return subTree0->data == subTree1->data &&
	     CheckSymmetric(subTree0->left, subTree1->right) &&
	      CheckSymmetric(subTree0->right, subTree1->left);
	   }
	   return 0;
}


int isSymmetric(const struct BTNode *tree) {

if( tree == NULL || CheckSymmetric(tree->left, tree->right))
	return 1;
else
	return 0;
}


int main() {
	char ch[1];
	int val;
	 gets(ch);
	 val = atoi(ch);

	 struct BTNode *root = (struct BTNode*)malloc(sizeof(struct BTNode));
	 struct BTNode *l1 = NULL;
	 struct BTNode *l2 = NULL;
	 root->data = 10;
	 root->left = NULL;
	 root->right = NULL;

	 switch(val) {
	 	case 0: 
	 			l1 = (struct BTNode*)malloc(sizeof(struct BTNode));
	 			l1->data = 100;
	 			l1->left = NULL;
	 			l1->right = NULL;

	 			struct BTNode *r1 = (struct BTNode*)malloc(sizeof(struct BTNode));
	 			r1->data = 100;
	 			r1->left = NULL;
	 			r1->right = NULL;

	 			root->left = l1;
	 			root->right = r1;
	 			break;
	 	case 1:
	 			l2 = (struct BTNode*)malloc(sizeof(struct BTNode));
	 			l2->data = 100;
	 			l2->left = NULL;
	 			l2->right = NULL;

	 			struct BTNode *r2 = (struct BTNode*)malloc(sizeof(struct BTNode));
	 			r2->data = 101;
	 			r2->left = NULL;
	 			r2->right = NULL;

	 			root->left = l2;
	 			root->right = r2;
	 			break;
	 	default: break;				
	 }

	 int result = isSymmetric(root);

	 if(result)
	 	printf("true");
	 else
	 	printf("false");


	 return 0;
}