#include <stdio.h>
#include <stdlib.h>
struct BSTNode {
	int data;
	struct BSTNode *left;
	struct BSTNode *right;
};


int SearchTarget(struct BSTNode * from,
	                struct BSTNode * target) {

	 struct BSTNode *iter = from;
	   while (iter && iter != target) {
	     iter = iter->data > target->data ? iter->left : iter->right;
	   }
	   if(iter == target)
	  return 1;
	else return 0;
	}



int sandwichedByNodes(struct BSTNode *anc_or_dec0,
					   struct BSTNode * anc_or_dec1, 
					   	struct BSTNode *middle) {


	struct BSTNode *search0 = anc_or_dec0;

	struct BSTNode *search1 = anc_or_dec1;
	  while (search0 != anc_or_dec1 &&
	         search0 != middle &&
	         search1 != anc_or_dec0 &&
	         search1 != middle &&
	         (search0 || search1)) {

	      if (search0) {
	        search0 = search0->data > middle->data ? search0->left : search0->right;
	     }

	      if (search1) {
	        search1 = search1->data > middle->data ? search1->left : search1->right;
	    }
	  }

	  if ((search0 != middle && search1 != middle) ||
	       search0 == anc_or_dec1 ||
	      search1 == anc_or_dec0) {
	      return 0;
	       }

	  return search0 == middle ? SearchTarget(middle, anc_or_dec1) : SearchTarget(middle, anc_or_dec0);


	return 1;
}


//creating new node method
struct BSTNode* newNode(int data)
{
	struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

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
			
		}
		else {
			temp = insert(node->right, data);
			node->right = temp;
			
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

int main() {
	struct BSTNode *root = NULL;
	struct BSTNode *top = NULL;
	struct BSTNode *mid = NULL;
	struct BSTNode *bot = NULL;

	int arr[100], len = 0, c, bytesread;

	char ch1[2],ch2[2],ch3[2];
	int val1,val2,val3;
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

	gets(ch1);
	val1 = atoi(ch1);
	top = getNodeWithValue(root,val1);
	gets(ch2);
	val2 = atoi(ch2);
	mid = getNodeWithValue(root,val2);
	gets(ch3);
	val3 = atoi(ch3);
	bot = getNodeWithValue(root,val3);

	int result = sandwichedByNodes(top,bot,mid);

	if(result) printf("True");
	else printf("False");
	return 0;
}