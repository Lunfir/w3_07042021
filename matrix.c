#include <stdio.h>

#define SIZE 5

void fill(int matrix[SIZE][SIZE], int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            matrix[row][col] = row;
        }
    }
}

int main(int argc, char const *argv[])
{
    int matrix[SIZE][SIZE];

    fill(matrix, SIZE);

    int limit = SIZE - 1;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < limit; col++) {
            printf("%d_", matrix[row][col]);
        }
        printf("%d\n", matrix[row][limit]);
    }

    int* p = &matrix[0][0];
    printf("matr[0][0]: %llu\n", matrix);
    printf("matr[0][1]: %llu\n", &matrix[0][1]);
    printf("matr[][]: %d\n", *(p+11));

    return 0;
}