#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct BSTNode
{
  int data;
  struct BSTNode *left;
  struct BSTNode *right;
};

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


int hasSumPath_HELPER(struct BSTNode* node, int partial_path_sum, int target) {
   
   
   if ( node == NULL) {
      return 0;
   }
   
   partial_path_sum = partial_path_sum + node->data;
   
   if (node->left == NULL && node->right == NULL) {
      return partial_path_sum == target;
   }
   
   return hasSumPath_HELPER(node->left, partial_path_sum,target) ||
   hasSumPath_HELPER(node->right, partial_path_sum,target);
}


int hasPathSum(struct BSTNode * tree, int target) {
   return hasSumPath_HELPER(tree, 0, target);
}

//main method.
int main()
{
  struct BSTNode *root = NULL;

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

  for(int j = 0 ;  j < len ; j++) {

    root = insert(root,arr[j]);

  }

  gets(ch);
  val = atoi(ch);
  

  if(hasPathSum(root,val))
  printf("True");
  else
  printf("False");

  return 0;

}