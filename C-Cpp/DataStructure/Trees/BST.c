#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary search tree node.
struct tree {
    int data;  // Stores the data of the node.
    struct tree* left;   // Pointer to the left child.
    struct tree* right;  // Pointer to the right child.
} *root = NULL;  // Global pointer to the root node of the BST, initially set to NULL.

// Function to create a new node with a given value.
struct tree* getNode(int x) {
    // Allocate memory for a new node.
    struct tree* var = (struct tree*)malloc(sizeof(struct tree));
    // Set the node's data and initialize its children as NULL.
    var->data = x;
    var->left = NULL;
    var->right = NULL;
    return var;  // Return the newly created node.
}

// Function to insert a new value into the BST.
struct tree* insert(struct tree* root, int x) {
    // If the tree is empty, create and return a new node as the root.
    if (root == NULL) {
        return getNode(x);
    }
    // Recursively insert the value in the left or right subtree.
    if (x < root->data) {
        // If the value is less than the root's data, go to the left subtree.
        root->left = insert(root->left, x);
    } else {
        // If the value is greater or equal, go to the right subtree.
        root->right = insert(root->right, x);
    }
    return root;  // Return the (unchanged) root node.
}

// Helper function to find the inorder predecessor (rightmost node in the left subtree).
struct tree* predecessor(struct tree* curr) {
    curr = curr->left;  // Move to the left subtree.
    // Go to the rightmost node in the left subtree (inorder predecessor).
    while (curr != NULL && curr->right != NULL) {
        curr = curr->right;
    }
    return curr;  // Return the predecessor node.
}

// Function to delete a node with a given value from the BST.
struct tree* delete(struct tree* root, int x) {
    // Base case: If the tree is empty, return NULL.
    if (root == NULL) {
        printf("Element %d not found in the tree.\n", x);
        return NULL;
    }

    // Recursively find the node to be deleted.
    if (root->data > x) {
        // If the value is smaller, move to the left subtree.
        root->left = delete(root->left, x);
    } else if (root->data < x) {
        // If the value is greater, move to the right subtree.
        root->right = delete(root->right, x); // Label: 2
    } else {
        // Node found, now handle the deletion cases.

        // Case 1: The node is a leaf node (no children).
        if (root->left == NULL && root->right == NULL) {
            free(root);  // Deallocate memory and return NULL.
            return NULL;
        }

        // Case 2: The node has only one child.
        if (root->left == NULL) {
            // Only right child exists.
            struct tree* temp = root->right;
            free(root);  // Free the current node.
            return temp; // Return the right child (Label: 1).
        }
        if (root->right == NULL) {
            // Only left child exists.
            struct tree* temp = root->left;
            free(root);  // Free the current node.
            return temp; // Return the left child.
        }

        // Case 3: The node has two children.
        // Find the inorder predecessor (largest value in the left subtree).
        struct tree* inPre = predecessor(root);
        // Replace the node's data with the predecessor's data.
        root->data = inPre->data;
        // Recursively delete the predecessor node.
        root->left = delete(root->left, inPre->data);
    }
    return root;  // Return the updated root node.
}

// Function to perform inorder traversal (Left, Root, Right).
void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);  // Visit left subtree.
        printf("%d ", root->data);  // Visit root.
        inorder(root->right); // Visit right subtree.
    }
}

// Function to perform preorder traversal (Root, Left, Right).
void preorder(struct tree* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Visit root.
        preorder(root->left);  // Visit left subtree.
        preorder(root->right); // Visit right subtree.
    }
}

// Function to perform postorder traversal (Left, Right, Root).
void postorder(struct tree* root) {
    if (root != NULL) {
        postorder(root->left);   // Visit left subtree.
        postorder(root->right);  // Visit right subtree.
        printf("%d ", root->data);  // Visit root.
    }
}

// Main function to drive the program.
int main() {
    // Insert some initial nodes into the tree.
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 8);

    // Perform initial deletions.
    printf("\n");
    root = delete(root, 3);  // Delete node with value 3.
    root = delete(root, 7);  // Delete node with value 7.

    // Perform an inorder traversal to display the tree.
    printf("The construction of tree is done and currently the traversal is: ");
    inorder(root);

    // Display menu options for inserting, deleting, and traversing the tree.
    printf("\nEnter:\n1. To insert an element\n2. To delete an element\n3. Inorder traversal\n4. Preorder traversal\n5. Postorder traversal");
    
    int n, x;
    // Loop to accept user inputs for various operations.
    do {
        printf("\nEnter case: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                // Insert a new element into the tree.
                printf("Enter the value to insert: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                // Delete an element from the tree.
                printf("Enter the value to delete: ");
                scanf("%d", &x);
                root = delete(root, x);
                break;
            case 3:
                // Inorder traversal of the tree.
                printf("The inorder traversal is: ");
                inorder(root);
                break;
            case 4:
                // Preorder traversal of the tree.
                printf("The preorder traversal is: ");
                preorder(root);
                break;
            case 5:
                // Postorder traversal of the tree.
                printf("The postorder traversal is: ");
                postorder(root);
                break;
            default:
                break;
        }
    } while (n < 6);  // Repeat until user chooses an exit case.

    return 0;  // End the program.
}
