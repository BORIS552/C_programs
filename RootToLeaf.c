
#include <stdio.h>
#include <stdlib.h>

struct BTNode {
   int data;
  struct BTNode *left, *right;
};


int SumRootToLeafHelper(struct BTNode *tree, int partial_sum) {

	if (tree == NULL) {
	     return 0;
 	 }

 	 partial_sum = partial_sum * 2 + tree->data;

   	if (tree->left == NULL && tree->right == NULL) {
	    return partial_sum;
	 }


	 return SumRootToLeafHelper(tree->left, partial_sum) +
	 SumRootToLeafHelper(tree->right, partial_sum);

}


int SumRootToLeaf(struct BTNode *tree) {
	return SumRootToLeafHelper(tree, 0);
}

int main()
{
  char ch[1];
	int val;
  struct BTNode *root = (struct BTNode*)malloc(sizeof(struct BTNode));
  struct BTNode *a = NULL;
  struct BTNode *g = NULL;
 	gets(ch);
	val = atoi(ch);
  root->data = 1;
  switch(val)
  {
    case 0:
            a =  (struct BTNode*)malloc(sizeof(struct BTNode));
            a->data = 1;
            a->right = NULL;
            a->left = NULL;

            struct BTNode *b = (struct BTNode*)malloc(sizeof(struct BTNode));
            b->data = 0;
            b->right = NULL;
            b->left = NULL;

            struct BTNode *c = (struct BTNode*)malloc(sizeof(struct BTNode));
            c->data = 0;
            c->right = NULL;
            c->left = NULL;

            struct BTNode *d = (struct BTNode*)malloc(sizeof(struct BTNode));
            d->data = 1;
            d->right = NULL;
            d->left = NULL;

            struct BTNode *e = (struct BTNode*)malloc(sizeof(struct BTNode));
            e->data = 1;
            e->right = NULL;
            e->left = NULL;

            struct BTNode *f = (struct BTNode*)malloc(sizeof(struct BTNode));
            f->data = 1;
            f->right = NULL;
            f->left = NULL;

            root->left = a;
            root->right = b;
            a->left = c;
            a->right = d;
            b->left = e;
            b->right = f;
            break;
            
    case 1: g =  (struct BTNode*)malloc(sizeof(struct BTNode));
            g->data = 1;
            g->right = NULL;
            g->left = NULL;

            struct BTNode *h = (struct BTNode*)malloc(sizeof(struct BTNode));
            h->data = 1;
            h->right = NULL;
            h->left = NULL;

           struct BTNode *i = (struct BTNode*)malloc(sizeof(struct BTNode));
            i->data = 1;
            i->right = NULL;
            i->left = NULL;

           struct BTNode *j = (struct BTNode*)malloc(sizeof(struct BTNode));
             j->data = 1;
             j->right = NULL;
             j->left = NULL;

            struct BTNode *k = (struct BTNode*)malloc(sizeof(struct BTNode));
             k->data = 1;
             k->right = NULL;
             k->left = NULL;

           struct BTNode *l = (struct BTNode*)malloc(sizeof(struct BTNode));
              l->data = 1;
              l->right = NULL;
              l->left = NULL;

              root->left = g;
             root->right = h;
             g->left = i;
             g->right = j;
             h->left = k;
              h->right = l;
               break;
                                                                      
                                                                      
                                                                      
             default: break;                                                         
                                                                      


  }

  int result = SumRootToLeaf(root);
  printf("%d ",result);
return 0;
}