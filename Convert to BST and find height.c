
#include<stdio.h> 
#include<stdlib.h> 
int x,z;
struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}; 
int height(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
}  
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 
struct Node* newNode(int key) 
{ 
	struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1;
	return(node); 
} 
struct Node *rightRotate(struct Node *y) 
{ 
	struct Node *x = y->left; 
	struct Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	// Return new root 
	return x; 
} 
struct Node *leftRotate(struct Node *x) 
{ 
	struct Node *y = x->right; 
	struct Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int getBalance(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
}  
struct Node* insert(struct Node* node, int key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else 
		return node; 
	node->height = 1 + max(height(node->left), 
						height(node->right)); 
	int balance = getBalance(node); 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		{z=1;
		return rightRotate(node);
		
	}

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		{ 
		z=2;
		return leftRotate(node);
	}
		 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{   z=3;
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
	    z=4;
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	x=height(node);
	return node; 
} 
void preOrder(struct Node *root) 
{ 
	if(root != NULL) 
	{ 
		printf("%d ", root->key); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 
int main() 
{ 
struct Node *root = NULL; 
root = insert(root, 10); 
root = insert(root, 20); 
root = insert(root, 30); 
root = insert(root, 40); 
root = insert(root, 50); 
root = insert(root, 25); 

/* The constructed Tree would be 
	     30 
	    /  \ 
	   20  40 
	  / \    \ 
	 10 25   50 
*/

printf("Preorder traversal of the constructed tree is \n"); 
preOrder(root); 
if(z=1)
  printf("\nL,L Rotation Performed");
else
if(z=2)
  printf("\nR,R Rotation Performed");
else
if(z=3)
  printf("\nL,R Rotation Performed");
else
if(z=4)
  printf("\nR,L Rotation Performed");  
printf("\nHeight of Balanced tree = %d",x);     
return 0; 
} 

