#include<stdio.h>
#include<stdlib.h>

struct BTNodes
{
  int data;
  struct BTNodes *left;
  struct BTNodes *right;
};

struct BTNodes *insert(struct BTNodes *root,int val)
{
  struct BTNodes *newNode = (struct BTNodes*)malloc(sizeof(struct BTNodes));
  newNode->data = val;
  newNode->right = NULL;
  newNode->left = NULL;

  if(root ==NULL)
  {
    root = newNode;
    return root;

  }
  struct BTNodes *cur  = root;
  struct BTNodes *parent = NULL;
  while(cur!= NULL)
  {
    parent =  cur;
    if(newNode->data > cur->data)
      cur = cur->right;
      else
      cur = cur->left;

  }
    if(newNode->data < parent->data)
    parent->left = newNode;
    else
    parent->right = newNode;
  return root;
}

void preOrderIteration(struct BTNodes *node)
{
  if(node == NULL)
  return;
  printf("%d ",node->data);
  preOrderIteration(node->left);
  preOrderIteration(node->right);
}


int main()
{
  struct BTNodes *root = NULL;
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
  preOrderIteration(root);
  return 0;

}