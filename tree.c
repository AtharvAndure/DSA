#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
    int data;
    struct Tree * right;
    struct Tree * left;   
}tree;
int main(){
    struct Tree * root=(tree *)malloc(sizeof(tree));
    root->data=50;
    root->left=NULL;
    root->right=NULL;
    return 0;
}