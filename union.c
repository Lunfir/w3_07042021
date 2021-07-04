#include <stdio.h>

typedef struct {
    char str[16];
    int x;
    double y;
    char z;
} Point;

typedef union {
    int x;
    double y;
    float z;
} Nums;

int main(int argc, char const *argv[])
{
    printf("struct: %d\n", sizeof(Point));
    printf("union: %d\n", sizeof(Nums));

    Nums num;

    num.y = 14.67;
    printf("num.y: %g\n", num.y);
    printf("num.x: %d\n", num.x);
    printf("num.z: %f\n", num.z);

    return 0;
}