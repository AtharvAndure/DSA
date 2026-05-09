#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
    int data;
    struct Tree * parent;
    struct Tree * right;
    struct Tree * left;   
}tree;

tree * createNode(int data,tree * parentNode){
    tree * new=(tree *)malloc(sizeof(tree));
    if(!new){
        printf("Unsucessful to Allocate Memory!");
        return NULL;
    }
    new->data=data;
    new->parent=parentNode;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void printInorder(tree * root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main(){

    int data;
    printf("\nEnter Root Node Data : ");
    scanf("%d",&data);
    tree * root= createNode(data,NULL);
    tree * current = root;

    int choice;
    while(1){
        printf("\n==================================");
        printf("\n[ CURRENT NODE: %d ]\n", current->data);
        printf("1. Add Left Child\n");
        printf("2. Add Right Child\n");
        printf("3. Move down to Left Child\n");
        printf("4. Move down to Right Child\n");
        printf("5. Backtrack (Move Up to Parent)\n");
        printf("6. Exit and Print Tree\n");
        printf("Choose an action: ");

        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(current->left!=NULL){
                printf("\nNode is Already Created => %d",current->left->data);
            }else{
                int data;
                printf("\nEnter Data : ");
                scanf("%d",&data);
                tree * left=createNode(data,current);
                current->left=left;
            }
            break;
        
        case 2:
            if(current->right!=NULL){
                printf("\nNode is Already Created => %d",current->right->data);
            }else{
                int data;
                printf("\nEnter Data : ");
                scanf("%d",&data);
                tree * right=createNode(data,current);
                current->right=right;
            }
            break;
        
        case 3:
            if(current->left!=NULL){
                current=current->left;
            }else{
                printf("\nThere is no Left Child Node");
            }
            break;
        
        case 4:
            if(current->right!=NULL){
                current=current->right;
            }else{
                printf("\nThere is no Right Child Node");
            }
            break;
        
        case 5:
            if(current->parent!=NULL){
                current=current->parent;
            }else{
                printf("\nWe are already on root Node");
            }
            break;
        case 6:
            printInorder(root);
            exit(0);

        default:printf("\nEnter Valid Choice Between(1-6)");
            break;
        }
    }
    return 0;
}