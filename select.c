#include <stdio.h>

void print(int arr[], int size) {
    int lim = size - 1;

    for (int i = 0; i < lim; i++) {
        printf("%d_", arr[i]);
    }

    printf("%d\n", arr[lim]);
}

// best:    reversed
// worst:   sorted
// average: -----
// time: 
// - best: O(N^N)
// - worst&average: O(N^N)
// memory:
// - O(1)
void selectSort(int arr[], int size) {
    for (int index = 0; index < size; index++) {
        int min = arr[index];
        int minIndex = index;
        int current;

        for (current = index; current < size; current++) {
            if (arr[current] < min) {
                min = arr[current];
                minIndex = current;
            }
        }

        arr[minIndex] = arr[index];
        arr[index] = min;
    }
}


int main(int argc, char const *argv[])
{
    int array[] = { 2, 4, 1, 8, 6, 3 };

    print(array, 6);

    selectSort(array, 6);

    print(array, 6);
    
    return 0;
}