#include <bits/stdc++.h>

#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
    int n;
    set<int> s;
    int sz;
    
    vector<int> store;

    map<int, int> mp;
    
    Solution(int N, vector<int>& blacklist) {
        n = N;
        
        sz = blacklist.size();
        for(auto x : blacklist)
        {
            s.insert(x);
        }
        srand(time(NULL));
    }
    
    int pick() {
        while(true) {
            int x = rand()%n;

            int ret_val = mp[x]==0?x:mp[x];
            if(s.find(ret_val) == s.end())
            {
                return ret_val;
            }
            else {
                int last = n-1;
                if(mp[last] == 0) {
                    mp[x] = last;
                }
                else {
                    mp[x] = mp[last];
                }
                n--;
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */