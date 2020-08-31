#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        long long ret = 0;
        long long M = 1e9 + 7;

        map<int, vector<pair<int, int> > >groupMp;
        map<int, int> cntMp;

        for(auto& r : rectangles) {
            groupMp[r[0]].push_back({r[1], 1});
            groupMp[r[0]].push_back({r[3], -1});
            
            groupMp[r[2]].push_back({r[1], -1});
            groupMp[r[2]].push_back({r[3], 1});
        }

        long long height = 0, start = 0, cnt = 0, prevX = 0;

        for(auto& x : groupMp) {
            ret = (ret + height * (x.first - prevX))%M;

            auto& v = x.second;
            for(auto& y : v) {
                cntMp[y.first] += y.second;

                if(cntMp[y.first] == 0) {
                    cntMp.erase(y.first);
                }
            }
            
            height = 0, start =0, cnt = 0;
            for(auto& y : cntMp) {
                if(cnt == 0) {
                    start = y.first;
                }
                cnt += y.second;
                if(cnt == 0) {
                    height += y.first - start;
                }
            }
            
            prevX = x.first;
        }

        return ret;
    }
};