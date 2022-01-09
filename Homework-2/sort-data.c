#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024

// Linked List struct.
struct Node{
    char *course;
    long code;
    struct Node* next;
};

/* struct Node *insert(struct Node *root, char *str, long l){
    if (root == NULL){
        root = (struct Node*)malloc(sizeof(struct Node));
        root->next = NULL;
        root->course = str;
        root->code = l;
        return root;
    } else if (root->next == NULL){
        if (root->code > l){
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->code = l;
            temp->course = str;
            temp->next = root;
            return temp;
        }
    }
} */

// Insert data to linked list.
void insert(struct Node *root, char *str, long l){
    // Find the last non-empty node.
    while(root->next != NULL){
        root = root->next;
    }
    // Create a new node at the end.
    root->next = (struct Node *)malloc(sizeof(struct Node));
    // Insert the data we got.
    root->next->course = str;
    root->next->code = l;
    // Set the next node pointer to null to avoid error.
    root->next->next = NULL;
}

// Prints the linked list.
void printList(struct Node* n){
    // Until next node is null print the data to screen.
    while(n != NULL){
        printf("%ld: %s\n", n->code, n->course);
        n = n->next;
    }
}

int main(void)
{
    // Create the root node of linked list.
    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    // To avoid a weird data in root node insert a temp value to it.
    root->course = "First";
    root->code = 0;
    // Set root's next pointer to null for avoiding error.
    root->next = NULL;
    // Create file pointer.
    FILE *file;
    // Read the file to this variable.
    char line[SIZE];
    // Used for adding data line by line to linked list.
    char *new;
    char *new2;
    char *p;
    long i;

    // Open our file as read only.
    file = fopen("Data.dat", "r");
    // Check if there was an error while opening the file.
    if (file == NULL)
        exit(EXIT_FAILURE);
    
    // Insert the data read from the file line by line to the linked list
    fread(&line, sizeof(char), SIZE, file);
    // Split the data when a new line is inserted.
    new = strtok(line, "\n");
    // For getting the course codes from lines.
    new2 = new;
    // Until the data is null add data to linked list.
    while(new != NULL)
	{
        // Add course codes to linked list.
        while(*new2){
            // Check if the character is a digit.
            if(isdigit(*new2)){
                // 
                i = strtol(new2, &new2, 10);
            }
            else{
                new2++;
            }
        }
        root = insert(root, new, i);
        new = strtok(NULL, "\n");
        new2 = new;
	}

    // Print the list
    printList(root);

    // Close the file pointer
    fclose(file);
    exit(EXIT_SUCCESS);
}