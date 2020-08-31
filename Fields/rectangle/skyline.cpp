#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector< vector<int> > ret;

        map<int, vector<pair<int, int> > > groupMp;

        map<int, int> cntMp;

        for(auto& x : buildings) {
            groupMp[x[0]].push_back({x[2], 1});
            groupMp[x[1]].push_back({x[2], -1});
        }

        int height = 0, start = 0, cnt = 0, prevHeight = 0;


        cntMp[0] = 1;
        for(auto& x : groupMp) {
            
            auto&v = x.second;
            for(auto& y : v) {
                cntMp[y.first] += y.second;

                if(cntMp[y.first] == 0) {
                    cntMp.erase(y.first);
                }
            }

            height = 0; start = 0; cnt = 0;
            height = cntMp.rbegin()->first;

            if(height != prevHeight)
                ret.push_back({x.first, height});

            prevHeight = height;
        }

        return ret;
    }
};