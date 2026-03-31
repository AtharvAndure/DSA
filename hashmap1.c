#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct{
    int key;
    char value[50];
}hashmap;

hashmap * table[MAX];

// Define array with NULL value 
void init_hashmap(){
    for (int i=0;i<MAX;i++){
        table[i]=NULL;
    }
}

int get_index(int key){
    return key % MAX;
}

// Insert Function
void insert_function(int key,char val[]){
    hashmap * new_memory = (hashmap *) malloc(sizeof(hashmap));
    new_memory->key=key;
    strcpy(new_memory->value, val);

    int index=get_index(key);
    int original_index=index;

    while(table[index]!=NULL){
        if(table[index]->key==key){   // Update Value if Key is available
            strcpy(table[index]->value, val); 
            free(new_memory);
            return;
        }

        // Else Keep Incrementing the Index
        index=(index+1)%MAX;

        if(index==original_index){
            printf("\nArray is Full\n");
            free(new_memory);
            return;
        }
    }

    // Else We found Empty Spot 

    table[index]=new_memory;
}

void search(int key){
    int index=get_index(key);
    int original_index=index;

    while(table[index]!=NULL){
        if(table[index]->key==key){
            printf("\nfound Element on Index : %d => Value : %s",index,table[index]->value);
            return;
        }
        index=(index+1)%MAX;
        if(index==original_index){
            break;
        }
        
    }
    printf("\nELement Not found..\n");
}


int main(){
    init_hashmap();
    int choice;

    while(1){
        printf("\nEnter Your Choice. \n1.Insert 2.Search 3.Restart Hashmap 4.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: {
            int key;
            char value[20];
            printf("\nEnter Key : Value => ");
            scanf("%d %s",&key,value);
            insert_function(key,value);
            break;
        }

        case 2:{
            int key;
            printf("\nEnter Key to Search : \n");
            scanf("%d",&key);
            search(key);
            break;
        }

        case 3:init_hashmap();
            break;
        
        case 4:exit(0);

        default: printf("\nInvalid Choice : ");
            break;
        }
    }
    return 0;
}
