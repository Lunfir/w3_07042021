#include <stdio.h>

void foo() {
    printf("foo\n");
}

int sum(int a, int b) {
    return a + b;
}

int predicate(int num, int divisor) {
    return num % divisor;
}

void handle_0(int num) {
    printf("%s\n", __PRETTY_FUNCTION__); // __FUNCTION__
    printf("Success!!!\n");
}

void handle_1(int num) {
    printf("%s\n", __PRETTY_FUNCTION__); // __FUNCTION__
    num += 2;
    printf("num: %d\n", num);
}

void handle_2(int num) {
    printf("%s\n", __PRETTY_FUNCTION__); // __FUNCTION__
    num *= num;
    printf("num: %d\n", num);
}

void mainHandler(int num, int div, 
                 int (*unaryPredicate)(int, int),
                 void (*arr[])(int)) {

    printf("%s\n", __PRETTY_FUNCTION__); // __FUNCTION__
    int result = unaryPredicate(num, div);

    printf("result: %d\n", result);

    arr[result](num);
}

int main(int argc, char const *argv[])
{
    void (*handlers[])(int) = {&handle_0, &handle_1, &handle_2};
    int (*predicatePtr)(int, int) = &predicate;
    int num, div;

    scanf("%d %d", &num, &div);

    mainHandler(num, div, predicatePtr, handlers);


    // void foo()
    // void (*fooPtr)();

    // fooPtr = foo;
    // fooPtr = &foo;

    // printf("fooPtr: %p\n", fooPtr);
    // printf("foo:     %p\n", &foo);
    // printf("foo:     %p\n", foo);

    // // int sum(int a, int b)
    // int (*sumPtr)(int, int) = &sum;

    // printf("sumPtr(3, 2):  %d\n", sumPtr(3, 2));
    // printf("*sumPtr(3, 4): %d\n", (*sumPtr)(3, 4));

    return 0;
}