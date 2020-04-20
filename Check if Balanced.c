

#include <stdio.h> 
#include <stdlib.h> 
#define bool int 
  
int x;  

struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* Returns the height of a binary tree */
int height(struct node* node); 
  

bool isBalanced(struct node* root) 
{ 
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */
  
    /* If tree is empty then return true */
    if (root == NULL) 
        return 1; 
  
    /* Get the height of left and right sub trees */
    lh = height(root->left); 
    rh = height(root->right); 
    x=lh-rh;
    
  
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) 
        return 1; 
  
    
    return 0; 
} 
  

  
/* returns maximum of two integers */
int max(int a, int b) 
{ 
    return (a >= b) ? a : b; 
} 
  
/*  The function Compute the "height" of a tree.*/
int height(struct node* node) 
{ 
    if (node == NULL) 
        return 0; 
  
    /* If tree is not empty then height = 1 + max of left 
      height and right heights */
    return 1 + max(height(node->left), height(node->right)); 
} 
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
        malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
  
int main() 
{ 
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->left->left = newNode(6); 
  
    if (isBalanced(root)) 
        printf("Tree is balanced"); 
    else
        printf("Tree is not balanced"); 
    if(x>=1)
	  printf("\nL,L Rotation");
	else
	if(x<=-1)
	   printf("\nR,R Rotation");   
	 /*     1
	      /  \
	     2    3
	   /  \
	 4     5
	/ 
   6	  
	   */      
  
    getchar(); 
    return 0; 
} 
