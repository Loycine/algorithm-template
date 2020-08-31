#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Point
{
public:
    int x,y;
    Point(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};

class Comparator
{
public:
    int operator() (const Point& a, const Point& b)
    {
        return a.x > b.x;
    }
};

int main()
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<Point, vector<Point>, Comparator> selfDefineDSHeap;

    for(int i=1; i<=5; i++)
        selfDefineDSHeap.push(Point(i, i+1));
    
    while(!selfDefineDSHeap.empty())
    {
        auto t = selfDefineDSHeap.top();
        cout << t.x << " " << t.y << "\n";
        selfDefineDSHeap.pop();
    }
}