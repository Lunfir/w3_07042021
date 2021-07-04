#include <iostream>

struct Point {
    int x;
    int y;

    // initial constructor
    Point(int inX = 0, int inY = 0) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        this->x = inX;
        this->y = inY;
    }

    // copy constructor
    Point(const Point& other) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        this->x = other.x;
        this->y = other.y;
    }

    Point& operator=(const Point& other) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        this->x = other.x;
        this->y = other.y;

        return *this;
    }

    Point operator+(const Point& other) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Point out;

        out.x = this->x + other.x;
        out.y = this->y + other.y;

        return out;
    }

    Point& operator++() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        this->x += 1;
        this->y += 1;

        return *this;
    }

    Point operator++(int) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Point old = *this;

        this->operator++();

        return old;
    }

    Point operator()(int mult) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Point out;

        out.x = this->x * mult;
        out.y = this->y * mult;

        return out;
    }
};

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
    os << "(" << obj.x <<", " << obj.y << ")";

    return os;
}

int main(int argc, char const *argv[])
{
    Point pointA = Point(5, -3);

    // init difference
    Point& ref = pointA;

    Point* ptr;
    ptr = &pointA;

    // use difference
    std::cout << ref << std::endl;
    std::cout << *ptr << std::endl;

    // re-reference
    Point pointPtr(42, 42);
    ptr = &pointPtr;
    std::cout << *ptr << std::endl;

    ref = pointPtr; // operator=()

    // copy constructor
    Point pointB = pointA; 

    // Point pointB;
    // pointB = pointA; // assignment operator

    // pointA + pointB;

    // std::cout << pointB << std::endl;
    
    //std::cout << pointA << std::endl;
    
    return 0;
}