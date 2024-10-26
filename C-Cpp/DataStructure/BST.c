// this is a code for BINARY SEARCH TREE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}Node;

typedef struct tree{
	Node *root;
	int size;
}Tree;

void init(Tree *tree){
	tree->root=NULL;
	tree->size=0;
}

Node* createNode(int x){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=x;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

Node* insertNode(Node *node, int x){
	if(node==NULL)
	{
		return createNode(x);							// IF IT IS NULL, THEN MAKE THE NODE FIRST AND THEN PROCEED
	}
	if(x < node->data){
		node->left=insertNode(node->left, x);			// WE RECURISIVELY GO TO LEFT TILL WE FIND A GREATER LEFT
	}
	else{
		node->right=insertNode(node->right, x);
	}
	return node;
}

void addNode(Tree *tree, int x){
	tree->root=insertNode(tree->root, x);
	tree->size++;										// THIS COUNTS THE NUMBER OF NODES PRESENT OVRERALL
}

// THE LOGICAL FLOW:-  addNode => insertNode <=> createNode

void inOrder(Node *root)
{
	if(root!=NULL){
		inOrder(root->left);							// GOES TO THE LEFT MOST SUBTREE
		printf("%d  ", root->data);						// PRINTS THE DATA
		inOrder(root->right);							// GOES TO THE RIGHT MOST SUBTREE
	}
}

int findMin(Node *root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root->data;
}

int findMax(Node *root){
	while(root->right!=NULL){
		root=root->right;
	}
	return root->data;
}

bool findNumber(Node *root, int x)
{
	if(root==NULL || x==root->data){
		return root!=NULL;					// AGAR ROOT NULL HUA, TOH WE CANT ACCESS DATA. ELSE, DATA TRUE RAHEGA
	}
	if(x < root->data){
		findNumber(root->left, x);
	}
	else{
		findNumber(root->right, x);
	}
}

/**
 * SUCCESSOR:- Next Greater Number
 * PREDESSOR:- Smaller Previous Number
 * */



void main()
{
	Tree tree1;
	init(&tree1);

	int choice=0;
	int data;
	int numFind=0;
	while(choice==0){
		printf("ENTER DATA (to exit, type -1):- ");
		scanf("%d", &data);	//no
		if(data==-1){
			inOrder(tree1.root);
			printf("\n");
			printf("THE MAXIMUM IS:- %d\n", findMax(tree1.root));
			printf("THE MINIMUM IS:- %d\n", findMin(tree1.root));

			printf("THE WHICH NUMBER YOU WISH TO FIND:- ");
			scanf("%d", &numFind);
			if(findNumber(tree1.root, numFind)){
				printf("FOUND");
			}
			else{
				printf("NOT FOUND");
			}
			printf("\n");
			exit(0);
		}
		addNode(&tree1, data);
		inOrder(tree1.root);
		printf("\n");
	}
}