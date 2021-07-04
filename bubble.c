#include <stdio.h>

// best:    sorted array
// worst:   reversed 
// average: -------
// time: 
// - best: O(N) opt/ O(N^N)
// - worst&average: O(N^N)
// memory:
// - O(1)
void bubbleSort(int arr[], int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 1; i < size; i++) {
            if ( arr[i-1] > arr[i] ) {
                int max = arr[i-1];

                arr[i-1] = arr[i];
                arr[i] = max;
            } 
        }
    }
}

void print(int arr[], int size) {
    int lim = size - 1;

    for (int i = 0; i < lim; i++) {
        printf("%d_", arr[i]);
    }

    printf("%d\n", arr[lim]);
}

int main(int argc, char const *argv[])
{
    int array[] = { 2, 4, 1, 8, 6, 3 };

    print(array, 6);

    bubbleSort(array, 6);

    print(array, 6);
    
    return 0;
}