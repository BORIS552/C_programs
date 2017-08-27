
#include <stdio.h>
#include <stdlib.h>
int len = 0,count = 0;
struct BSTNode
{
	int data;
	struct BSTNode *left;
	struct BSTNode *right;
};

// method to create a node
struct BSTNode* newNode (int data)
{
	struct BSTNode *temp = (struct BSTNode*) malloc( sizeof(struct BSTNode) );

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}


struct BSTNode* constructTreeUtil (int arr[], int* arrIndex,
								int low, int high, int size)
{
	// Base case
	if (*arrIndex >= size || low > high)
		return NULL;

	
	struct BSTNode* root = newNode ( arr[*arrIndex] );
	*arrIndex = *arrIndex + 1;

	
	if (low == high)
		return root;

		int i;
	for ( i = low; i <= high; ++i )
		if ( arr[ i ] > root->data )
			break;

	root->left = constructTreeUtil ( arr, arrIndex, *arrIndex, i - 1, size );
	root->right = constructTreeUtil ( arr, arrIndex, i, high, size );

	return root;
}


struct BSTNode *constructTree (int arr[], int size)
{
	int arrIndex = 0;
	return constructTreeUtil (arr, &arrIndex, 0, size - 1, size);
}

// method to print preorder traversal of a Binary Tree
void preOrder (struct BSTNode* node)
{
	
	if (node == NULL || count == len)
		return;
	printf("%d ", node->data);
	count++;
	preOrder(node->left);
	preOrder(node->right);
}


int main ()
{


	int arr[100], c, bytesread;
	char input[100];
	fgets(input, sizeof(input), stdin);
	char* input1 = input;

	/* converting string of numbers with spaces into integer array.*/
	
	while(sscanf(input1,"%d%n", &c, &bytesread) > 0) {
			arr[len++] = c;
			input1 = input1 + bytesread;
	}

	int size = sizeof( arr ) / sizeof( arr[0] );

	struct BSTNode *root = constructTree(arr, size);

	
	preOrder(root);

	return 0;
}
