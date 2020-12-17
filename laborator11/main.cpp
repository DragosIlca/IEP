#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

using namespace std;

class Point {
    public: 
        int x, y;

        Point(int x, int y) : x(x), y(y) {};
};

class Figure {
    private:
        std::vector<Point> points;

    public: 
        Figure(std::vector<Point> points): points(points) {};

        std::vector<Point> getPoints() {
            return points;
        }
};

class Diamond : public Figure {
    public:
        Diamond(std::vector<Point> points) : Figure(points) {};
};

template<typename T>
float getSlope(T &figure) {
    static_assert(std::is_base_of<Figure, T>::value, "Must be of type Figure");

    std::vector<Point> localPoints = figure.getPoints();
    
    if (localPoints.size() >= 2) {
        return (localPoints[1].y - localPoints[0].y) / (localPoints[1].x - localPoints[0].x);
    }

    else {
        cout << "Nu se poate frate, nu s destule puncte\n ";
        return 0;
    }
}

int main() {
    Point p1(1, 3);
    Point p2(2, 6);

    std::vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);

    Diamond f1(points);

    cout << getSlope(f1) << "\n";

    return 0;
}