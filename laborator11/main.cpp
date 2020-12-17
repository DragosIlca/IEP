#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Point {
    public: 
        int x, y;
};

class Figure {
    private:
        std::vector<Point> points;

    public: 
        Figure(std::vector<Point> points): points(points) {};
};

int main() {

    return 0;
}