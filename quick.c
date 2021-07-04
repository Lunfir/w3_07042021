#include <stdio.h>

void print(int arr[], int size) {
    int lim = size - 1;

    for (int i = 0; i < lim; i++) {
        printf("%d_", arr[i]);
    }

    printf("%d\n", arr[lim]);
}

// time: O(NlogN)
// memory:
// - O(N)

int partition(int array[], int lo, int hi) {
    int pivotIndex = (lo + hi) / 2;
    int tmp = array[hi];

    array[hi] = array[pivotIndex];
    array[pivotIndex] = tmp;

    for ( pivotIndex = lo; array[pivotIndex] < array[hi]; pivotIndex++);

    for (int index = pivotIndex + 1; index < hi; index++) {
        if (array[index] < array[hi]) {
            tmp = array[index];
            array[index] = array[pivotIndex];
            array[pivotIndex] = tmp;
            pivotIndex += 1;
        }
    }

    tmp = array[hi];
    array[hi] = array[pivotIndex];
    array[pivotIndex] = tmp;

    return pivotIndex;
}

void quickSort(int array[], int lo, int hi) {
    if (lo < hi) {
        int pivotIndex = partition(array, lo, hi);

        quickSort(array, lo, pivotIndex-1);
        quickSort(array, pivotIndex+1, hi);
    }
}


int main(int argc, char const *argv[])
{
    int array[] = { 2, 7, 4, 3, 5, 6, 4, 1, 2, 4 };

    print(array, 10);

    //quickSort(array, 0, 8);

    quickSort(array, 0, 9);

    print(array, 10);
    
    return 0;
}