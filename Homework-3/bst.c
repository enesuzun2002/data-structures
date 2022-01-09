#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for binary search tree.
struct treeNode{
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};
typedef struct treeNode TreeNode;

typedef TreeNode *TreeNodePtr;

// Inserts the given value to the correct node in binary search tree
TreeNodePtr insertNode(TreeNodePtr treePtr, int value){
    // Creates an empty node and sets leftPtr, rightPtr nodes to null if the binary search tree is null
    if (treePtr == NULL){
        TreeNodePtr root = (TreeNodePtr)malloc(sizeof(TreeNodePtr));
        root -> leftPtr = NULL;
        root -> rightPtr = NULL;
        root -> data = value;
        return root;
    }
    // If given value is bigger then the data at the current node return the right node
    if (treePtr -> data < value){
        treePtr -> rightPtr = insertNode(treePtr -> rightPtr, value);
        return treePtr;
    }
    // Else return left node
    treePtr -> leftPtr = insertNode(treePtr -> leftPtr, value);
    return treePtr;
}

// Traverses the tree with preorder and prints to screen
void preorder(TreeNodePtr treePtr){
    if (treePtr == NULL)
        return;

    printf("%d ", treePtr->data);
    preorder(treePtr->leftPtr);
    preorder(treePtr->rightPtr);
}

// Traverses the tree with inorder and prints to screen
void inorder(TreeNodePtr treePtr){
    if (treePtr == NULL)
        return;
    
    inorder(treePtr->leftPtr);
    printf("%d ", treePtr->data);
    inorder(treePtr->rightPtr);
}

// Traverses the tree with postorder and prints to screen.
void postorder(TreeNodePtr treePtr){
    if (treePtr == NULL)
        return;
    
    postorder(treePtr->leftPtr);
    postorder(treePtr->rightPtr);
    printf("%d ", treePtr->data);
}

int randomNumber(){
    int num = (rand() % (25)) + 1;
}

void main(){
    TreeNodePtr treePtr = NULL;
    int i;

    // Seed for random number generation.
    srand(time(0));

    // Run this loop for 10 times.
    for (i = 0; i < 10; i++){
        /* Call insertNode function with value as our randomNumber() function which generates random numbers everytime the program runs.
         * Set the node value we get from our insertNode function to our treePtr variable. 
         */
        treePtr = insertNode(treePtr, randomNumber());
    }
    printf("Preordered Binary Search Tree: ");
    preorder(treePtr);
    printf("\n");
    printf("Inordered Binary Search Tree: ");
    inorder(treePtr);
    printf("\n");
    printf("Postordered Binary Search Tree: ");
    postorder(treePtr);
    printf("\n");
}