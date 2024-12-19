// Tree vertex splitting
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode
{
    int vertex;
    int distance = 0;
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
void TVS(int i, TreeNode *tree, int delta, int *d, int N)
{
    if (tree[i].vertex != -1)
    { // If the node exists
        if (2 * i > N) // if the node is a leaf node
        { 
            d[i] = 0;
        }
        else{
            TVS(2*i, tree, delta, d, N);
            d[i] = max(d[i], d[2*i]+tree[2*i].distance);
            if(2*i + 1 <= N){
                TVS(2*i+1, tree, delta, d, N);
                d[i] = max(d[i],d[2*i+1]+tree[2*i+1].distance);
            }
        }
        if((tree[i].vertex != 1) && (d[i]+tree[i].distance > delta)){
            d[i] = 0;
            static int k = 0;
            cout<<"splited vertex "<<++k<<" = "<<tree[i].vertex<<endl;
        }

    }
}

int main()
{
    int h = 3;
    int N = pow(2, h + 1) - 1;
    TreeNode tree[] = {{}, {1, 0}, {2, 4}, {3, 2}, {-1, 0}, {4, 2}, {5, 1}, {6, 3}, {-1, 0}, {-1, 0}, {7, 1}, {8, 4}, {-1, 0}, {-1, 0}, {9, 2}, {10, 3}}; //{vertex, distance of vertex from its parent}
    int delta = 5;
    int d[N+1] = {0};
    TVS(1, tree, delta, d, N);

    return 0;
}
