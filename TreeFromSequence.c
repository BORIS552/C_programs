/* program to construct tree using inorder and preorder traversals */
#include<stdio.h>
#include<stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
int data;
struct node* left;
struct node* right;
};

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value);
struct node* newNode(int data);


struct node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
static int preIndex = 0;

if(inStrt > inEnd)
	return NULL;

struct node *tNode = newNode(pre[preIndex++]);
if(inStrt == inEnd)
	return tNode;
int inIndex = search(in, inStrt, inEnd, tNode->data);
tNode->left = buildTree(in, pre, inStrt, inIndex-1);
tNode->right = buildTree(in, pre, inIndex+1, inEnd);

return tNode;
}


int search(int arr[], int strt, int end, int value)
{
int i;
	for(i = strt; i <= end; i++)
	{
		if(arr[i] == value)
		return i;
	}
	
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
struct node* node = (struct node*)malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

/* This funtcion is here just to test buildTree() */
void printInorder(struct node* node)
{
if (node == NULL)
	return;

/* first recur on left child */
printInorder(node->left);

/* then print the data of node */
printf("%c ", node->data);

/* now recur on right child */
printInorder(node->right);
}


int main()
{
	//Preorder List
	int pre[100], len1 = 0, c1, bytesread1;
	char input[100];
	fgets(input, sizeof(input), stdin);
	char* input1 = input;
	/* converting string of numbers with spaces into integer array.*/
	while(sscanf(input1,"%d%n", &c1, &bytesread1) > 0) {
			pre[len1++] = c1;
			input1 = input1 + bytesread1;
	}

	//Inorder List
	int in[100], len2 = 0, c2, bytesread2;
	char input2[100];
	fgets(input2, sizeof(input2), stdin);
	char* input21 = input2;
	/* converting string of numbers with spaces into integer array.*/
	while(sscanf(input21,"%d%n", &c2, &bytesread2) > 0) {
			pre[len2++] = c2;
			input21 = input21 + bytesread2;
	}



struct node *root = buildTree(in, pre, 0, len1 - 1);

/* Let us test the built tree by printing Insorder traversal */
printf("Inorder traversal of the constructed tree is \n");
printInorder(root);
return 0;
}