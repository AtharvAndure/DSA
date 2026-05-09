#include <stdio.h>
#include <stdlib.h>

// Node structure with a parent pointer for easy backtracking
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent; 
};

// Function to create a new node
struct Node* createNode(int data, struct Node* parentNode) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parentNode;
    return newNode;
}

// Inorder traversal to verify the final tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int val, choice;
    
    printf("Enter root node data: ");
    scanf("%d", &val);
    
    // Initialize root. It has no parent, so parent is NULL.
    struct Node* root = createNode(val, NULL);
    struct Node* current = root; // 'current' tracks where the user is in the tree

    while (1) {
        printf("\n==================================");
        printf("\n[ CURRENT NODE: %d ]\n", current->data);
        printf("1. Add Left Child\n");
        printf("2. Add Right Child\n");
        printf("3. Move down to Left Child\n");
        printf("4. Move down to Right Child\n");
        printf("5. Backtrack (Move Up to Parent)\n");
        printf("6. Exit and Print Tree\n");
        printf("Choose an action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (current->left != NULL) {
                    printf("-> ERROR: Left child already exists (%d).\n", current->left->data);
                } else {
                    printf("Enter data for left child: ");
                    scanf("%d", &val);
                    current->left = createNode(val, current);
                    printf("-> Added %d as left child of %d.\n", val, current->data);
                }
                break;
                
            case 2:
                if (current->right != NULL) {
                    printf("-> ERROR: Right child already exists (%d).\n", current->right->data);
                } else {
                    printf("Enter data for right child: ");
                    scanf("%d", &val);
                    current->right = createNode(val, current);
                    printf("-> Added %d as right child of %d.\n", val, current->data);
                }
                break;
                
            case 3:
                if (current->left != NULL) {
                    current = current->left;
                } else {
                    printf("-> ERROR: No left child exists to move to.\n");
                }
                break;
                
            case 4:
                if (current->right != NULL) {
                    current = current->right;
                } else {
                    printf("-> ERROR: No right child exists to move to.\n");
                }
                break;
                
            case 5:
                if (current->parent != NULL) {
                    current = current->parent;
                    printf("-> Backtracked up to %d.\n", current->data);
                } else {
                    printf("-> ERROR: You are at the Root node. Cannot backtrack further.\n");
                }
                break;
                
            case 6:
                printf("\nTree Construction Ended.\n");
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                exit(0);
                
            default:
                printf("-> Invalid choice. Try again.\n");
        }
    }

    return 0;
}