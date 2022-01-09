/* 
 * Data Structures Assignment-1
 * Enes Murat Uzun
 * 201180035
 */


// Libraries included.
#include <stdio.h>
#include <stdbool.h>

// Queue size
#define SIZE 10

// Element stucture
typedef struct
{
    // variables of the element structure 
    int front;
    int rear;
    int value;
    int itemCount;
} element;

element el;

element queue[SIZE];

// Checks if the queue is full.
bool isFull()
{
    return el.itemCount == SIZE;
}

// Checks if the queue is empty.
bool isEmpty()
{
    return el.itemCount == 0;
}

// Prints values of the queue elements.
void print_queue(){
    // Check if queue is empty.
    if(!isEmpty()){
        // If queue isn't empty print values of the elements.
        printf("Your queue: ");
        // Write every elements value using a for loop.
        for(int i = ++el.front ;i <= el.rear ;i++){
            printf("%d ",queue[i].value);
        }
    // When queue is empty it prints the message.
    } else {
        printf("Queue is empty");
    }
}

// Add x to the queue.
void enqueue(int x)
{
    // Check if the queue is full.
    if (!isFull())
    {
        // If queue isn't full add x to the next elements value.
        queue[++el.rear].value = x;
        // Increment itemCount variable.
        el.itemCount++;
    } else {
        printf("Queue is full!");
    }
}

// First element is removed from queue
int dequeue()
{
    if (isEmpty())
    {
        return 0;
    // Checks if front and rear is equal.
    } else if (el.front == el.rear){
        // When they are equal it means queue is completely dequeued and there are no items inside so we reset the variables to their initial values.
        el.rear = -1;
        el.front = -1;
        el.itemCount = 0;
    } else {
        // First element is removed from the list and item value is lowered by 1.
        el.itemCount--;
        return queue[++el.front].value;
    }
}

// Lists some options to the user.
void options()
{
    // Create some variables.
    int selection;
    int x;
    int removed_item;
    while (true)
    {
        printf("---------OPTIONS---------\n");
        printf("0 - Print all elements of the queue\n");
        printf("1 - Add an element into the queue\n");
        printf("2 - Remove element from the queue\n");
        printf("3 - Exit\n");
        printf("Select (0-3)? : ");
        scanf("%d", &selection);
        // Check what user wants.
        if (selection == 0){
            // First sort the queue then print.
            queueToArray();
            print_queue();
        }
        else if (selection == 1){
            // Add user given values to queue.
            printf("Write the integer to add into the queue: ");
            scanf("%d", &x);
            enqueue(x);
        }
        else if (selection == 2){
            // Remove the first element of the queue.
            removed_item = dequeue();
            printf("Removed item from queue: %d", removed_item);
        }
        else if (selection == 3){
            // Break the loop and exit the program
            break;
        }
    }
}

// Convert queue to an array to sort it.
void queueToArray(){
    // Create a new array.
    int newArray[SIZE-1];
    int l;
    // Add values from queue to the newly created array using a for loop.
    for(int i = ++el.front;i<=el.rear;i++){
        newArray[l] = queue[i].value;
        l++;
    }
    // Call the sorting method.
    sort(newArray);
}

// Sorts the newly created array.
void sort(int newArray[]){
    int l = 0;
    int temp;
    // Compares every value in the list one by one and sorts it.
    for(int i = 0; i <= SIZE; i++){                             // i = 0 and j = 1, i = 0 and j = 2, i = 0 and j = 3 etc.
        for (int j = i + 1; j <= SIZE - 1; j++){
            // If the value at the index j is smaller then the value at index i swap their values.
            if (newArray[j] < newArray[i]){
                temp = newArray[i];
                newArray[i] = newArray[j];
                newArray[j] = temp;
            }
        }
    }
    // Add sorted values to our queue.
    arrayToQueue(newArray);
}

// Doesn't convert array to queue but it deletes every value in queue and adds the sorted ones from the new array.
void arrayToQueue(int newArray[]){
    // Run deqeue() till the queue is empty.
    while (!isEmpty()){
        dequeue();
    }
    // Add sorted values to the queue using a for loop.
    for(int i = 0; i <= SIZE; i++){
        enqueue(newArray[i]);
    }
}

void main()
{
    // Initial values for the variables.
    el.front = -1;
    el.rear = -1;
    el.itemCount = 0;
    options();
}