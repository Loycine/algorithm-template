#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


class BIT{
public:
    vector<int> a;
    int n;

    void init(int n)
    {
        this->n = n;
        a = vector<int> (n+1);
        for(int i=0; i<=n; i++)
        {
            a[i] = 0;
        }
    }

    int lowbit(int i)
    {
        return i & (-i);
    }

    void add(int x, int v)
    {
        for(int i=x; i<=n; i+=lowbit(i))
        {
            a[i] += v;
        }
    }

    int sum(int x)
    {
        int s = 0;
        for(int i=x; i>0; i-=lowbit(i))
        {
            s += a[i];
        }
        return s;
    }
};


class BIT2D{
public:
    int n;
    vector<vector<int> >a;

    void init(int n)
    {
        this->n = n;
        a = vector<vector<int> > (n+1);
        for(int i=0; i<=n; i++)
        {
            a[i] = vector<int> (n+1);
            for(int j=0; j<=n; ++j)
            {
                a[i][j] = 0; 
            }
        }
    }

    int lowbit(int i)
    {
        return i & (-i);
    }

    void add(int x, int y, int v)
    {
        for(int i=x; i<=n; i+=lowbit(i))
        {
            for(int j=y; j<=n; j+=lowbit(j))
            {
                a[i][j] += v;
            }
        }
    }

    int query(int l, int b, int r, int t)
    {
        return sum(r, t) - sum(l-1, t) - sum(r, b-1) + sum(l-1, b-1);
    }

    int sum(int x, int y)
    {
        int s = 0;
        for(int i=x; i>0; i-=lowbit(i))
        {
            for(int j=y; j>0; j-=lowbit(j))
            {
                s += a[i][j];
            }
        }
        return s;
    }
};
