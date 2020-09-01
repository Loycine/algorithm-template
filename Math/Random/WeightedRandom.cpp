#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> w;
    int sum = 0;
    vector<int> s;

    Solution(vector<int>& w) : w(w){
        sum = 0;
        for(auto x : w) {
            sum += x;
            s.push_back(sum);
        }    
    }
    
    const int M = 1e3;


    int randsum() {
        int randMax = (M-1)*M*M + (M-1)*M + M-1;
        int tail = randMax % sum;

        if(tail != sum -1)
            randMax = randMax - tail - 1;


        while(true) {
            int ret = (rand()%M) * M * M + (rand()%M) * M  + (rand()%M);

            
            if(ret < randMax) {
                return ret % sum + 1;
            }
        }
    }

    int pickIndex() {
        int weight = randsum();

        return lower_bound(s.begin(), s.end(), weight) - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main()
{
    cout << RAND_MAX << "\n";
}