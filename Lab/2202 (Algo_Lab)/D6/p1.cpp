//doesn't work . needs debugging
// Convex Hull, Brute-force
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

struct Point
{
    int x, y;
};

// To find orientation of ordered triplet (p1, p2, p).
// The function returns following values
// 0 --> p1, p2 and p are collinear
// 1 --> AntiClockwise
// -1 --> Clockwise
int findSide(Point p1, Point p2, Point p)
{

    int val = (p.y - p1.y) * (p2.x - p1.x) -
              (p.x - p1.x) * (p2.y - p1.y);

    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}
bool operator ==(Point &p1 , Point &p2){
    if(p1.x == p2.x && p1.y == p2.y)
        return true;
    return false;
}
void convexHullBrute(vector<Point> &points, int n)
{
    if (n < 3)
        cout << "\nConvex hull is not possible" << endl
             << endl;
    else
    {
        vector<Point> hull;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                Point p1 = points[i];
                Point p2 = points[j];
                // line segment <p1,p2>
                if(p1 == p2) // we have duplicate points in points vector . skip these 
                    break;
                bool isEdge = true;
                int side1 = 0, side2 = 0;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                    {
                        Point p3 = points[k];
                        int orient = findSide(p1, p2, p3);

                        if (orient == 0){ // Points are collinear and on the line segment
                            continue;
                            
                        }
                        else if (orient == 1)
                            side1++;
                        else
                            side2++;

                        if (side1 > 0 && side2 > 0)
                        {
                            isEdge = false;
                            break;
                        }
                    }
                }
                if (isEdge)
                { // line segment <p1,p2> is an edge. so, p1 and p2 are on the hull
                    cout<<"\n("<<p1.x<<","<<p1.y<<")---->("<<p2.x<<","<<p2.y<<")"<<endl;
                    hull.push_back(p1);
                    hull.push_back(p2);
                }
            }
        }
        // remove duplicate points from the hull
        for (int i = 1; i < hull.size(); ++i)
        {
            for (int k = 0; k < i; ++k)
            {
                if (hull.at(i).x == hull.at(k).x && hull.at(i).y == hull.at(k).y)
                {
                    // remove element if already present
                    hull.erase(hull.begin() + i);
                    --i;
                    break;
                }
            }
        }

        // print the convex hull
        cout << "\nThe points on the convex hull are: " << endl;
        for (auto i : hull)
            cout << "(" << i.x << ", " << i.y << ") ";
        cout << endl
             << endl;
    }
}

// Driver program to test above functions
int main()
{
    clock_t start,end;

    ifstream inputFile("ConvexHull.txt"); // Replace with your input file name

    if (!inputFile.is_open())
    {
        cout << "Error opening the file.\n";
        return 1;
    }

    int k = 0;
    vector<Point> points;
    while (!inputFile.eof())
    {
        // cout<<"k = "<<k<<endl;
        int x, y;
        inputFile >> x >> y;
        Point p{x, y};
        points.push_back(p);
        k++;
    }

    start = clock();
    convexHullBrute(points, k);
    end = clock();
    float time = (float)(end - start)/CLOCKS_PER_SEC*1000;
    cout<<"\nBrute Convex Hull: "<<time<<" ms"<<endl<<endl;


    inputFile.close();
    return 0;
}
