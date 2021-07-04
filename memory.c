#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void fill(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr+i) = 13;
    }
}

void print(int arr[], int size) {
    int limit = size - 1;

    for (int i = 0; i < limit; i++) {
        printf("%d_", arr[i]);
    }

    printf("%d\n", arr[limit]);
}

int main(int argc, char const *argv[])
{
    // stack
    //int arr[10];

    // heap
    int* array;
    int* tmp;

    array = (int*)malloc(SIZE * sizeof(int));
    // array = (int*)calloc(SIZE, SIZE * sizeof(int));

    if (array == NULL) {
        printf("ERROR\n");
        return 0;
    }

    fill(array, SIZE);
    print(array, SIZE);

    // implicit conversion from void* to int*
    tmp = realloc(array, SIZE * 2 * sizeof(int));

    if (tmp == NULL) {
        printf("ERROR\n");
        free(array);

        return 0;
    }

    print(tmp, SIZE * 2);
    
    free(tmp);
    printf("free(tmp)\n");

    return 0;
}
