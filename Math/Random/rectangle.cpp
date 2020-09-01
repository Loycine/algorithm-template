#include <bits/stdc++.h>
#include <cstdlib>

#include <ctime>
using namespace std;


class WeightRandom {
public:
    vector<int> w;
    int sum = 0;
    vector<int> s;

    WeightRandom(vector<int>& w) : w(w){
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

class Solution {
public:
    WeightRandom* wr;
    vector<int> w;

    vector<vector<int>> rects;

    Solution(vector<vector<int>>& rects) : rects(rects) {
        for(auto&r : rects) {
            w.push_back( (r[2]-r[0]+1) * (r[3]-r[1]+1) );
        }

        wr = new WeightRandom(w);
    }
    
    vector<int> pick() {
        vector<int> ret;

        int idx = wr->pickIndex();

        auto& r = rects[idx];
        int dx = r[2]-r[0]+1;
        int dy = r[3]-r[1]+1;

        dx = rand()%dx;
        dy = rand()%dy;

        ret.push_back(r[0] + dx);
        ret.push_back(r[1] + dy);
        return ret;
    }
};