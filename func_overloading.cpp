#include <iostream>
#include <string>

// functions overloading
int sum(int a, int b) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    return a + b;
}

float sum(float a, float b) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    return a + b;
}

std::string sum(std::string str1, std::string str2) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    return str1 + str2;
}

// templates
template <typename T>
T foo(T a, T b) {
    //std::cout << __PRETTY_FUNCTION__ << std::endl;

    return a + b;
}

template<typename X, typename Y, typename Z>
Z mult(X a, Y b) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    return a * b;
}

int main(int argc, char const *argv[])
{
    const float f = 1.23;
    const float d = 4.7;

    std::cout << "foo<int>(12, 23): "       << foo<int>(12, 23) << std::endl;
    std::cout << "foo<int>(1.23f, 5.f): "   << foo<int>(1.23f, 5.f) << std::endl;
    std::cout << "foo<float>(1.23f, 5.f): " << foo<float>(1.23f, 5.f) << std::endl;
    std::cout << "foo<str>(): "             << foo<std::string>("abc", "def") << std::endl;

    std::cout <<  mult<int, int, float>(1, 2) << std::endl;
    std::cout <<  mult<float, int, float>(1.2f, 2) << std::endl;
    
    return 0;
}