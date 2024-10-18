#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates
  // a->used only *after* the array has been accessed. Therefore a->used can go
  // up to a->size
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void removeAtArray(Array *a, int index) {
  if (index >= a->size || index < 0) {
    printf("Error: Index out of bounds!\n");
    return;
  }

  // Shift elements to the left starting from the index to remove
  for (int i = index; i < a->size - 1; i++) {
    a->array[i] = a->array[i + 1];
  }

  // Decrease the size of the array
  a->used--;
}

void printArray(Array *a) {
  for (int i = 0; i < a->used; i++) {
    printf("%d ", a->array[i]);
  }
  printf("\n");
}