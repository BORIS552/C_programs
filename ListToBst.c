#include<stdio.h>
#include<stdlib.h>

struct ListNode {
   int data;
   struct ListNode* next;
};

struct BSTNode {
   int data;
   struct BSTNode* left;
   struct BSTNode* right;
};




//method for inserting data to linkedList.
void push(struct ListNode **head,int data) {
	struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = data;
	node->next = *head;
	*head = node;
}


int countListNodes(struct ListNode *head) {
   int count = 0;
   struct ListNode *temp = head;
   while(temp){
      temp = temp->next;
      count++;
   }
   return count;
}



struct BSTNode* sortedListToBSTRecur(struct ListNode **head_ref, int n) {
   
   if (n <= 0)
      return NULL;
   
   /* Recursively construct the left subtree */
   struct BSTNode *left = sortedListToBSTRecur(head_ref, n/2);
   
   /* Allocate memory for root, and link the above constructed left
    subtree with root */
   struct BSTNode *root = (struct BSTNode*)malloc(sizeof(struct BSTNode));
   root->data = ((*head_ref)->data);
   root->left = left;
   
   /* Change head pointer of Linked List for parent recursive calls */
   *head_ref = (*head_ref)->next;
   
   /* Recursively construct the right subtree and link it with root
    The number of nodes in right subtree  is total nodes - nodes in
    left subtree - 1 (for root) which is n-n/2-1*/
   root->right = sortedListToBSTRecur(head_ref, n-n/2-1);
   
   return root;
}

struct BSTNode* sortedListToBST(struct ListNode *head) {
   
   
   int n = countListNodes(head);
   return sortedListToBSTRecur(&head, n);
}

void printPreorder(struct BSTNode* node){
   if (node == NULL)
      return;
   printf("%d ", node->data);
   printPreorder(node->left);
   printPreorder(node->right);
}

int main()
{
	struct ListNode *head = NULL;
	struct BSTNode *root = NULL;
	int arr[100], len = 0, c, bytesread;
	char input[100];
	fgets(input, sizeof(input), stdin);
	char* input1 = input;

	while(sscanf(input1,"%d%n", &c, &bytesread) > 0) {
			arr[len++] = c;
			input1 = input1 + bytesread;
	}

	for(int i = 0; i < len; i++)
		push(&head,arr[i]);

		root = sortedListToBST(head);

		 printPreorder(root);
	return 0;
}