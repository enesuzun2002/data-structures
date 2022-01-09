#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
}

void insert(struct Node *root, int x){
    while(root->next != NULL){
        root = root->next;
    }
    root->next = (struct Node *)malloc(sizeof(struct Node));
    root->next->data = x;
    root->next->next = NULL;
}

void main(){

    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 20;
    root->next = NULL;
    insert(root, 35); 
    printList(root);
}