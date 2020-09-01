#include<bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

class Solution {
public:
    const double PI = acos(-1);

    double r, xc, yc;
    Solution(double radius, double x_center, double y_center) {
        r =radius;
        xc = x_center;
        yc = y_center;
        srand(time(NULL));
    }
    
    vector<double> randPoint() {
        vector<double> ret;

        while(true) {
            int flag = rand()%2;
            double r_rate = rand()/(double)RAND_MAX;
            int sign = flag?1:-1;

            double x = r * r_rate * sign + xc;

            flag = rand()%2;
            r_rate = rand()/(double)RAND_MAX;
            sign = flag?1:-1;
            double y = r * r_rate * sign + yc;

            if(pow(x-xc, 2) + pow(y-yc, 2) < pow(r, 2)) {
                ret.push_back(x);
                ret.push_back(y);
                return ret;
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main()
{
    double pi = acos(-1);
    cout << acos(-1) << "\n";
    cout << cos(pi) << "\n";
    cout << sin(pi/2) << "\n";
}