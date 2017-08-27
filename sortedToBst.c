#include<stdio.h>
#include<stdlib.h>
 
int count = 0,len = 0;
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};
 
struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)
                         malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}

struct TNode* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;
 

    int mid = (start + end)/2;
    struct TNode *root = newNode(arr[mid]);
 
    
    root->left =  sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}
 


 

void preOrder(struct TNode* node)
{
    if (node == NULL || count == len)
        return;
    printf("%d ", node->data);
    count++;
    preOrder(node->left);
    preOrder(node->right);
}
 

int main()
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

    int n = len;
    
    struct TNode *root = sortedArrayToBST(arr, 0, n-1);
    printf("n PreOrder Traversal of constructed BST ");
    preOrder(root);
 
    return 0;
}