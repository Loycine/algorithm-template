#include <bits/stdc++.h>
using namespace std;

int a[10] = {1, 2, 3 ,5, 7, 9};

int main()
{
    //lower_bound more than can be equal to the left
    int idx1 = lower_bound(a, a+5 ,2) - a;

    //upper_bound more than
    int idx2 = upper_bound(a, a+5 ,2) - a;

    //output 1 2
    cout << idx1 << " " << idx2 << "\n";
}