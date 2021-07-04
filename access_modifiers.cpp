#include <iostream>

// struct's methods & attrs are public by default
struct Point {
    // initial constructor
    Point(int inX = 0, int inY = 0) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        this->x = inX;
        this->y = inY;
    }

    int getX() const {
        return this->x;
    }

    int getY() const {
        return this->y;
    }

    void setX(int x) {
        if (x % 2 == 0) {
            this->x = x;
        }
    }

    void setY(int y) {
        this->y = y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& obj);
    friend struct Vector;
    
private:
    int x;
    int y;

    void tmp() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
    os << "(" << obj.x <<", " << obj.y << ")";

    return os;
}

struct Vector
{
    Vector(const Point& start, const Point& end) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        this->x = start.x - end.x;
        this->y = start.y - end.y;
    }

private:
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    Point pointA = Point(5, -3);
    pointA.setX(42);

    Vector vec(Point(2, 3), Point(1, 1));

    std::cout << pointA << std::endl;
    
    return 0;
}