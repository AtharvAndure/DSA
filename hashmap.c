#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 100

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hash table structure
typedef struct {
    Node* key;      // store node address
    int isOccupied; // 0 = empty, 1 = filled
} HashNode;

HashNode hashTable[SIZE];

// Hash function (convert pointer to integer safely)
int hash(Node* key) {
    return ((uintptr_t)key) % SIZE;
}

// Insert node address into hashmap
void insert(Node* key) {
    int index = hash(key);

    while (hashTable[index].isOccupied == 1) {
        if (hashTable[index].key == key)
            return; // already present

        index = (index + 1) % SIZE; // linear probing
    }

    hashTable[index].key = key;
    hashTable[index].isOccupied = 1;
}

// Search node address in hashmap
int search(Node* key) {
    int index = hash(key);
    int startIndex = index;

    while (hashTable[index].isOccupied != 0) {

        if (hashTable[index].key == key)
            return 1; // found

        index = (index + 1) % SIZE;

        if (index == startIndex)
            break; // full cycle
    }

    return 0; // not found
}

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {

    // Create linked list: 1 -> 2 -> 3
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // Traverse and mark visited
    Node* temp = head;

    while (temp != NULL) {

        if (search(temp)) {
            printf("Cycle detected at node with data %d\n", temp->data);
            break;
        }

        printf("Visiting node %d\n", temp->data);
        insert(temp);

        temp = temp->next;
    }

    return 0;
}