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

void merge(int array[], int lo, int mid, int hi) {
    int size = hi - lo;
    int buffer[size];
    int buffIndex = 0;
    int j = mid;
    int i = lo;

    for( ; i < mid && j < hi; buffIndex++) {
        if (array[i] < array[j]) {
            buffer[buffIndex] = array[i];
            i += 1;
        } else {
            buffer[buffIndex] = array[j];
            j += 1;
        }
    }

    for ( ; i < mid; i++, buffIndex++) {
        buffer[buffIndex] = array[i];
    }

    for ( ; j < hi; j++, buffIndex++) {
        buffer[buffIndex] = array[j];
    }

    for (buffIndex = 0; buffIndex < size; buffIndex++, lo++) {
        array[lo] = buffer[buffIndex];
    }
}

void mergeSort(int array[], int lo, int hi) {
    int mid = (lo + hi) / 2;

    if (mid == lo) {
        return;
    }

    mergeSort(array, lo, mid);
    mergeSort(array, mid, hi);

    merge(array, lo, mid, hi);
}


int main(int argc, char const *argv[])
{
    int array[] = { 2, 3, 4, 5, 7, 8, 12, 1, 2, 4 };

    print(array, 10);

    mergeSort(array, 0, 10);

    print(array, 10);
    
    return 0;
}