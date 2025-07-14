//Convex Hull , QuickHull
#include<iostream>
#include <fstream>
#include<vector>
#include<set>
#include <ctime>
using namespace std;


// Stores the result (points of convex hull)
set<pair<int, int>> hull;



// Returns the side of point p with respect to line
// joining points p1 and p2.
int findSide(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
	int val = (p.second - p1.second) * (p2.first - p1.first) -
			  (p.first - p1.first) * (p2.second - p1.second);

	if (val > 0)
		return 1;
	if (val < 0)
		return -1;
	return 0;
}

// returns a value proportional to the distance
// between the point p and the line joining the
// points p1 and p2
int lineDist(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
	return abs((p.second - p1.second) * (p2.first - p1.first) -
			    (p.first - p1.first) * (p2.second - p1.second));
}





// End points of line L are p1 and p2. side can have value
// 1 or -1 specifying each of the parts made by the line L
void quickHull(vector<pair<int, int>>& points, int n, pair<int, int> p1, pair<int, int> p2, int side)
{
	int index = -1; // index of the point with maximum distance from the line <p1,p2>
	int max_dist = 0;

	// finding the point with maximum distance
	// from L and also on the specified side of L.
	for (int i=0; i<n; i++) //there is no need to check all the points . checking only cthe the points in the sub problems is enough
	{
		int temp = lineDist(p1, p2, points[i]);
		if (findSide(p1, p2, points[i]) == side && temp > max_dist)
		{
			index = i;
			max_dist = temp;
		}
	}

    //Base case
	// If no point is found, add the end points
	// of L to the convex hull.
	if (index == -1)
	{
		hull.insert(p1);
		hull.insert(p2);
		return;
	}

	// Recur for the two parts divided by a[index]
	// quickHull(a, n, a[index], p1, -findSide(a[ind], p1, p2));
	// quickHull(a, n, a[index], p2, -findSide(a[ind], p2, p1));
	quickHull(points, n, p1, points[index], side);
	quickHull(points, n, points[index], p2, side);
}




void printHull(vector<pair<int, int>>& a, int n)
{
	// a[i].second -> y-coordinate of the ith point
	if (n < 3)
	{
		cout << "Convex hull not possible\n";
		return;
	}

	// Finding the point with minimum and
	// maximum x-coordinate
	int min_x = 0, max_x = 0;
	for (int i=1; i<n; i++)
	{
		if (a[i].first < a[min_x].first)
			min_x = i;
		else if (a[i].first > a[max_x].first)
			max_x = i;
	}

	// Recursively find convex hull points on
	// one side of line joining a[min_x] and
	// a[max_x]
	quickHull(a, n, a[min_x], a[max_x], 1);

	// Recursively find convex hull points on
	// other side of line joining a[min_x] and
	// a[max_x]
	quickHull(a, n, a[min_x], a[max_x], -1);

	cout << "\nThe Points on the Convex Hull are:\n";
	while (!hull.empty())
	{
		cout << "(" <<( *hull.begin()).first << ", "
			<< (*hull.begin()).second << ") ";
		hull.erase(hull.begin());
	}
	cout<<endl<<endl;
}

// Driver code
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
	vector <pair<int, int>> points;
    while (!inputFile.eof())
    {
		//cout<<"k = "<<k<<endl;
		int x,y;
		inputFile>>x>>y;
		points.push_back(make_pair(x,y));
		k++;
	}

	start = clock();
	printHull(points, k);
    end = clock();
    float time = (float)(end - start)/CLOCKS_PER_SEC*1000;
    cout<<"\nQuick Hull: "<<time<<" ms"<<endl<<endl;
	inputFile.close();
	return 0;
}
