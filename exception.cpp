#include <iostream>

struct PointException {
    const char* what() {
        return "Point exc";
    }
};

struct Point {
public:
    // initial constructor
    Point(int inX = 0, int inY = 0) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        if (inX < 0 || inY < 0) {
            throw PointException();
        }

        this->x = inX;
        this->y = inY;
    }

private:
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    try {
        Point point = Point(13, 54);

        std::cout << "After exception" << std::endl;
    } catch(PointException& e) {
        std::cout << e.what() << std::endl;

        // return 0;
    }
    
    std::cout << "After try-catch" << std::endl;

    return 0;
}