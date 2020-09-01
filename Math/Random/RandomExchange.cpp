#include <bits/stdc++.h>
#include <cstdlib>

#include <ctime>
using namespace std;

namespace RejectSampling {
class Solution {
public:
    set<pair<int, int> > mp;
    int n, m;
    
    Solution(int n_rows, int n_cols) {
        n = n_cols;
        m = n_cols;
        srand(time(NULL));
    }
    
    vector<int> flip() {
        while(true) {
            vector<int> ret;
            int x = rand()%n;
            int y = rand()%m;

            if(mp.find({x, y}) == mp.end()) {
                mp.insert({x, y});
                ret.push_back(x);
                ret.push_back(y);
                return ret;
            }
        }
    }
    
    void reset() {
        mp.clear();
    }
};
};


namespace shufftle{
class Solution {
public:
    map<int,int> mp;
    int n, m;

    int tot;
    int last;

    Solution(int n_rows, int n_cols) {
        n = n_rows;
        m = n_cols;
        reset();
        srand(time(NULL));
    }
    
    vector<int> flip() {
        vector<int> ret;
        int ret_val;

        last = tot -1;
        int val = rand()%tot;

        if(mp[val] == 0)
        {
            ret_val = val;
        } else {
            ret_val = mp[val];
        }

        ret.push_back(ret_val / m);
        ret.push_back(ret_val % m);
        if(mp[last] == 0)
            mp[val] = last;
        else
            mp[val] = mp[last];
        tot --;
        
        return ret;
    }
    
    void reset() {
        mp.clear();
        tot = n * m; 
    }
};
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
