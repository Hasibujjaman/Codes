// Convex Hull, Graham's Scan
#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
using namespace std;

struct Point
{
	int x, y;
};

// A global point needed for sorting points with reference
// to the first point Used in compare function of qsort()
Point p0;

// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

// A utility function to swap two points
void swap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
int distSq(Point p1, Point p2)
{
	return (p1.x - p2.x) * (p1.x - p2.x) +
		   (p1.y - p2.y) * (p1.y - p2.y);
}

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

// A function used by library function qsort() to sort an array of points with respect to the first point
// A pointer to a function that that compares two elements. It returns
// a negative integer if the first argument is less than the second
// a positive integer if the first argument is greater than the second
// zero if both arguments are equal
int compare(const void *vp1, const void *vp2)
{
	Point *p1 = (Point *)vp1;
	Point *p2 = (Point *)vp2;

	// Find orientation
	int o = findSide(p0, *p1, *p2);
	if (o == 0)
		return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

	return (o == 1) ? -1 : 1; // when <p0p2> is on the left of <p0p1> findSide returns 1. As <p0p2> is on the left of <p0p1>, it has bigger angle .
							  // i.e, <p0p1> has smaller angle so we return -1 in that case . otherwise 1.
}

// Prints convex hull of a set of n points.
void grahamScan(vector<Point> &points, int n)
{
	// Find the bottommost point
	int ymin = points[0].y, min = 0;
	for (int i = 1; i < n; i++)
	{
		int y = points[i].y;

		// Pick the bottom-most or choose the left
		// most point in case of tie
		if ((y < ymin) || (ymin == y & points[i].x < points[min].x))
			ymin = points[i].y, min = i;
	}

	// Place the bottom-most point at first position
	swap(points[0], points[min]);

	// Sort n-1 points with respect to the first point.
	// A point p1 comes before p2 in sorted output if p2
	// has larger polar angle (in counterclockwise
	// direction) than p1
	p0 = points[0];
	qsort(&points[1], n - 1, sizeof(Point), compare);

	// If two or more points make same angle with p0,
	// Remove all but the one that is farthest from p0
	// Keep the farthest point at the end when more than one points have same angle.
	int m = 1; // Initialize size of modified array
	for (int i = 1; i < n; i++)
	{
		// Keep removing i while angle of i and i+1 is same
		// with respect to p0
		while (i < n - 1 && findSide(p0, points[i], points[i + 1]) == 0)
			i++;

		points[m] = points[i];
		m++; // Update size of modified array
	}

	// If modified array of points has less than 3 points,
	// convex hull is not possible
	if (m < 3)
		return;

	// Create an empty stack and push first three points
	// to it.
	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);

	// Process remaining m-3 points
	for (int i = 3; i < m; i++)
	{
		// Keep removing top while the angle formed by
		// points next-to-top, top, and points[i] makes
		// a non-left turn
		while (S.size() > 1 && findSide(nextToTop(S), S.top(), points[i]) <= 0)
			S.pop();

		S.push(points[i]);
	}

	// Now stack has the output points, print contents of stack
	cout << "\nThe points on the convex hull are: " << endl;
	while (!S.empty())
	{
		Point p = S.top();
		cout << "(" << p.x << ", " << p.y << ") ";
		S.pop();
	}
	cout << endl
		 << endl;
}

// Driver program to test above functions
int main()
{
	clock_t start, end;

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
	grahamScan(points, k);
	end = clock();
	float time = (float)(end - start) / CLOCKS_PER_SEC * 1000;
	cout << "\nGraham's Scan: " << time << " ms" << endl
		 << endl;
	inputFile.close();
	return 0;
}
