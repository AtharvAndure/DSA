#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    int data;
    struct List * next;
}list;

list * createNode(int data){
    list * new = (list *)malloc(sizeof(list));
    if(!new){
        printf("Failed To ALlocate Memory!");
        return NULL;
    }
    new->data=data;
    new->next=NULL;
}

void appendNode(list ** head,int data){
    if(*head==NULL){
        *head=createNode(data);
        return;
    }
    list * temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=createNode(data);
}

void printList(list * head){
    if(head==NULL){
        printf("List is Empty!\n");
        return;
    }
    printf("%d ",head->data);
    printList(head->next);
    printf("%d ",head->data);
}

int main(){
    list * head=NULL;
    appendNode(&head,10);
    appendNode(&head,20);
    appendNode(&head,30);
    appendNode(&head,40);
    appendNode(&head,50);
    printList(head);
    
    return 0;
}