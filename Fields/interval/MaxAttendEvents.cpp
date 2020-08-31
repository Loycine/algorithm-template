#include <set>
#include <vector>
#include <map>
#include <queue>

#include <iostream>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int ret = 0;

        multiset<pair<int, int> > st;
        
        int maxTime = -1;
        int minTime = 0x3fffffff;
        
        for(auto & e : events)
        {
            st.insert(make_pair(e[0],e[1]));
            minTime = min(minTime, e[0]);
            maxTime = max(maxTime, e[1]);
        }

        priority_queue<int> q;
        
        int cur = minTime;
        while(!st.empty() || !q.empty())
        {
            auto it_start = st.begin();

            auto it_end = st.upper_bound(make_pair(cur, maxTime));
            
            for(auto it=it_start; it!=it_end; it++)
            {
                q.push(it->second);
            }
            
            st.erase(it_start, it_end);
            
            while(!q.empty())
            {
                int endTime = q.top();
                if(endTime >= cur)
                {
                    q.pop();
                    ret++;
                    break;
                }
                q.pop();
            }
            
            cur ++;
            while(!q.empty())
            {
                int endTime = q.top();
                if(endTime >= cur)
                {
                    break;
                }
                q.pop();
            }
        }

        return ret;
    }
};

int main()
{
    Solution sln;
    vector<vector<int> > events={{1,2},{2,3}};
    cout << sln.maxEvents(events) << "\n";
}