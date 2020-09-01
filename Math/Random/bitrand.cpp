// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

#include <bits/stdc++.h>
#include <cstdlib>

#include <ctime>
using namespace std;

int rand7()
{
    return rand()%7 + 1;
}

class Solution {
public:
    int rand10() {
        while(true) {
            int ret = (rand7()-1) * 7 + (rand7()-1);
            if(ret < 40) {
                return ret % 10 + 1;
            }
        }
    }
};

const int maxn = 15;
const int testCases = 1e6;

int cnt[maxn];

int main() {
    srand(time(NULL));
    Solution sln;

    for(int i=0; i<testCases; i++)
        cnt[sln.rand10()] ++ ;
    
    for(int i=1; i<=10 ;i++)
    {
        cout << cnt[i] << " ";
    }
    cout << "\n";
}