
 #include<stdio.h>
 #include<stdlib.h>

struct BSTNode {

int data;

struct BSTNode *right,*left,*parent;

};


struct BSTNode* findSuccessor(struct BSTNode *node) {
 
 struct BSTNode *iter = node;
 if(iter->right != NULL) {
 	iter = iter -> right;
 	while(iter ->left) {
 		iter = iter -> left;
 	}
 	return iter;
 }
 while(iter->parent != NULL && iter ->parent->right == iter) {
 	iter = iter->parent;
 }

 return iter->parent;
}

//creating new node method
struct BSTNode* newNode(int data)
{
	struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;
	node -> parent = NULL;

	return (node);
}

// method for inserting data into root
struct BSTNode* insert(struct BSTNode *node, int data) {

	if(node == NULL) return (newNode(data)); // for empty tree.
	else {
		struct BSTNode *temp;
		if(data <= node->data) {
			temp = insert(node->left,data);
			node->left = temp;
			temp->parent = node;
		}
		else {
			temp = insert(node->right, data);
			node->right = temp;
			temp->parent = node;
		}
		return node;
	}
}

//method for searching for the node having the value.
struct BSTNode* getNodeWithValue(struct BSTNode *node, int val) {
	
	while (node->data != val) {
      if (node->left && val < node->data) {
         node = node->left;
      } else if (node->right && val >= node->data) {
         node = node->right;
      }
   }
   return node;
}


//main method.
int main() {
	struct BSTNode* root = NULL, *temp;

	int arr[100], len = 0, c, bytesread;

	char ch[2];
	int val;
	char input[100];
	fgets(input, sizeof(input), stdin);
	char* input1 = input;

	/* converting string of numbers with spaces into integer array.*/
	
	while(sscanf(input1,"%d%n", &c, &bytesread) > 0) {
			arr[len++] = c;
			input1 = input1 + bytesread;
	}
	
	

	
	printf("\n");
	for(int i = 0; i <= len-1; i++) {
	printf("%d,",arr[i] );
	}
	

	// code for creating tree.
	
	for(int j = 0 ;  j < len ; j++) {

		root = insert(root,arr[j]);

	}

printf("Enter the val\n");
gets(ch);
val = atoi(ch);
printf(" \n value is %d\n", val);
  	/*
  	root = insert(root,20);
  	root = insert(root,8);
  	root = insert(root, 22);
  	root = insert(root, 4);
  	root = insert(root, 12);
  	root = insert(root, 10);
  	root = insert(root, 14);
  	*/

  	temp = root->left->right->right;
  		//val = temp -> data;
  	struct BSTNode *nodeForSuccessor = getNodeWithValue(root, val);

  	struct BSTNode *successor  = findSuccessor(nodeForSuccessor);

  	printf("\n %d", successor->data);
return 0;
}