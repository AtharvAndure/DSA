// Link List Programs , contian All sort of basic program which is needed in the program
// 1. Creating LinkList.
// 2. Appending Dynamically.
// 3. Add and Delete Node from Start , Beginning and Ending of the node.
// 4. Sort Element Using Bubble Sort Algorithm.
// 5. Show List.

#include <stdio.h>
#include <stdlib.h>

// Node Struture.
typedef struct List
{
    int data;
    struct List *next;
} list;

// Append Node Dynamically and Return it.
list *createNode(int data)
{
    list *node = (list *)malloc(sizeof(list));
    if (!node)
    {
        printf("\nMemmory Fault");
    }
    else
    {
        node->data = data;
        node->next = NULL;
        return node;
    }
}

// Append Node at the end of the List.
void appendNode(list **l, int data)
{
    list *new = createNode(data);
    list *temp = *l;
    if (*l == NULL)
    {
        *l = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = new;
    }
}

// Remove Last Node.
void removeLastElement(list **l){
    list * temp=*l;
    if(*l==NULL){
        printf("\nList is Empty");
    }else if(temp->next==NULL){
        free(*l);
        *l=NULL;
    }
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
    }
}

// Remove First Node.
void removeFirstElement(list **l)
{
    if (*l == NULL)
    {
        printf("\nlist is Empty");
    }
    else
    {
        list *head = (*l)->next;
        *l = head;
    }

}

// Add Node at the Beginning.
void addAtFirst(list **l, int data)
{
    list *new = createNode(data);

    if (*l == NULL)
    {
        *l = new;
    }
    else
    {
        new->next = *l;
        *l=new;
    }
}

// Add Node in Between.
void addAtBetween(list **l,int data,int pos){
    list * temp=*l;
    list * new = createNode(data);
    int count=1;

    if(*l==NULL){
        *l=new;
    }else{
        while(temp->next!=NULL && count!=pos){
            temp=temp->next;
            count++;
        }
        new->next=temp->next;
        temp->next=new;
    }
}


// Remove Node in Between.
void removeBetweenElement(list ** l,int pos){
    list * temp=*l;
    int count=1;
    if(*l==NULL){
        printf("\nList is Empty!");
    }else if(temp->next==NULL){
        free(*l);
        *l=NULL;
    }else{
        while(temp->next->next!=NULL && count<pos){
            temp=temp->next;
            count++;
        }
        temp->next=temp->next->next;
    }
}

// Sort the List Using Bubble Sort.
void sortList(list **l){
    if (*l == NULL || (*l)->next == NULL) return;
    int temp;
    for(list *i=*l;i->next->next!=NULL;i=i->next){
        for(list *j=*l;j->next->next!=NULL;j=j->next){
            if(j->data > j->next->data){
                temp = j->data;
                j->data=j->next->data;
                j->next->data=temp;
            }
        }
    }
}

// Use Bubble Sort
void display(list *lis)
{
    printf("\n");
    while (lis != NULL)
    {
        printf(" %d >", lis->data);
        lis = lis->next;
    }
    printf("\n");
}

int main()
{
    list *head = NULL;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    display(head);

    removeFirstElement(&head);
    removeFirstElement(&head);

    display(head);

    addAtFirst(&head,50);
    
    display(head);

    removeLastElement(&head);
    
    display(head);
    
    addAtBetween(&head,15,1);
    
    display(head);

    appendNode(&head, 60);
    appendNode(&head, 70);
    appendNode(&head, 90);
    appendNode(&head, 80);

    removeBetweenElement(&head,2);
    removeBetweenElement(&head,3);

    display(head);
    sortList(&head);
    display(head);

    return 0;
}