#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

void generateRandomPoints(int numPoints, int minX, int maxX, int minY, int maxY, std::vector<Point>& points) {
    points.clear();
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < numPoints; ++i) {
        Point p;
        p.x = rand() % (maxX - minX + 1) + minX;
        p.y = rand() % (maxY - minY + 1) + minY;
        points.push_back(p);
    }
}

void writePointsToFile(const std::vector<Point>& points, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file for writing." << std::endl;
        return;
    }

    for (const Point& p : points) {
        file << p.x << " " << p.y << "\n";
    }

    file.close();
}

int main() {
    int numPoints;
    cout<<"Enter number of points to generate: ";
    cin>> numPoints;
    int minX = -10, maxX = 10;
    int minY = -10, maxY = 10;

    std::vector<Point> points;
    generateRandomPoints(numPoints, minX, maxX, minY, maxY, points);

    std::string filename = "my2Dpoints.txt";
    writePointsToFile(points, filename);

    std::cout << "Generated " << numPoints << " points and stored them in " << filename << std::endl;

    return 0;
}
