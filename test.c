#include <stdio.h>

int sum(int a, int b) {
    printf("%s\n", __PRETTY_FUNCTION__);

    return a + b;
}

// float sum(float a, float b) {
//     return a + b;
// }

int main(int argc, char const *argv[])
{
    sum(2, 4);
    
    return 0;
}
