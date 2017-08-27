#include<stdio.h>
#include<stdlib.h>
struct BSTNode
{
  int data;
  struct BSTNode *left;
  struct BSTNode *right;
};


struct BSTNode* LargestAfterK(struct BSTNode *root, int k)
{
  struct BSTNode * subtree =root;
  struct BSTNode *first_so_far = NULL;
   
   while (subtree) {
      if (subtree->data > k) {
         first_so_far = subtree;
         subtree = subtree->left;
      } else {
         subtree = subtree->right;
      }
   }
   return first_so_far;
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

struct BSTNode* insert(struct BSTNode *node,int data)
{
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


int main()
{
  struct BSTNode *root;
  struct BSTNode *node;
  char ch[2];
  int val;
  int arr[100], len = 0, c, bytesread;
  char input[100];
  fgets(input, sizeof(input), stdin);
  char* input1 = input;

  /* converting string of numbers with spaces into integer array.*/
  
  while(sscanf(input1,"%d%n", &c, &bytesread) > 0) {
      arr[len++] = c;
      input1 = input1 + bytesread;
  }

  for(int i = 0; i < len;i++)
  {
    root = insert(root,arr[i]);
  }

  gets(ch);
  val = atoi(ch);
  
  node = LargestAfterK(root,val);
  printf("%d",node->data);
  return 0;

}