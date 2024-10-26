#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
    int data;
    struct node* right;
    struct node* left;
} Node;

typedef struct tree {
    Node *root;
    int totNodes;
} Tree;

void init(Tree *tree) {
    tree->root = NULL;
    tree->totNodes = 0;
}

Node* makeNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node* node) {
    if (node == NULL) return 0;
    int leftH = height(node->left);
    int rightH = height(node->right);
    return (leftH > rightH ? leftH : rightH) + 1; // Add 1 for the current node
}

int balance(Node *node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

Node* insertNode(Tree *tree, Node *node, int x) {
    if (node == NULL) {
        return makeNode(x);
    }

    if (x < node->data) {
        node->left = insertNode(tree, node->left, x);
    }
    else if (x > node->data) {
        node->right = insertNode(tree, node->right, x);
    }
    else {
        return node; // Duplicate keys not allowed
    }

    int bal = balance(node);
    printf("%d has the balance factor %d\n", node->data, bal); // prints the balance factor

    return node; // Return the (unchanged) node pointer
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void add(Tree *tree, int x) {
    tree->root = insertNode(tree, tree->root, x);
    (tree->totNodes)++;
}

int main() {
    Tree tree;
    init(&tree);

    add(&tree, 5);
    add(&tree, 2);
    add(&tree, 9);
    add(&tree, 10);
    add(&tree, 345);
    add(&tree, 6);
    add(&tree, 7);

    printf("Inorder traversal: ");
    inOrder(tree.root);
    return 0;
}
