
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};


struct node* bintree2listUtil(struct node* root)
{
	// Base case
	if (root == NULL)
		return root;

	
	if (root->left != NULL)
	{	
		struct node* left = bintree2listUtil(root->left);
		for (; left->right!=NULL; left=left->right);
		left->right = root;
		root->left = left;
	}

	
	if (root->right!=NULL)
	{
		
		struct node* right = bintree2listUtil(root->right);
		for (; right->left!=NULL; right = right->left);
		right->left = root;
		root->right = right;
	}

	return root;
}


struct node* bintree2list(struct node *root)
{
	// Base case
	if (root == NULL)
		return root;

	
	root = bintree2listUtil(root);
	while (root->left != NULL)
		root = root->left;

	return (root);
}


/* Function to print nodes in a given doubly linked list */
void printList(struct node *node)
{
	while (node!=NULL)
	{
		printf("%d ", node->data);
		node = node->right;
	}
}



//creating new node method
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;
	

	return (node);
}

// method for inserting data into root
struct node* insert(struct node *node, int data) {

	if(node == NULL) return (newNode(data)); // for empty tree.
	else {
		struct node *temp;
		if(data <= node->data) {
			temp = insert(node->left,data);
			node->left = temp;
			
		}
		else {
			temp = insert(node->right, data);
			node->right = temp;
			
		}
		return node;
	}
}







int main()
{
	struct node *root = NULL;
	// Let us create the tree shown in above diagram
	int arr[100], len = 0, c, bytesread;
	char input[100];
	fgets(input, sizeof(input), stdin);
	char* input1 = input;

	/* converting string of numbers with spaces into integer array.*/
	
	while(sscanf(input1,"%d%n", &c, &bytesread) > 0) {
			arr[len++] = c;
			input1 = input1 + bytesread;
	}

	for(int j = 0 ;  j < len ; j++) {

		root = insert(root,arr[j]);

	}

	// Convert to DLL
	struct node *head = bintree2list(root);
	printList(head);

	return 0;
}
