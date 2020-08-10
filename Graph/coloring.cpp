#include <list>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;


namespace bipartition
{
class Solution {
public:
    const static int maxn = 2000 + 5;
    list<int> graph[maxn];
    int color[maxn];
    int n;
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        n = N;
        bool ok = true;
        
        memset(color, -1, sizeof(color));

        int m = dislikes.size();
        for(int i=0; i<m; i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i=1 ;i<=n; i++)
        {
            if(color[i] != -1)
            {
                continue;
            }
            ok = dfs(i, 0);
            if(!ok)
            {
                return false;
            }
        }
        return true;
    }
    

    bool dfs(int head, int cur_color)
    {
        color[head] = cur_color;
        
        for(int node : graph[head])
        {
            if(color[node] == -1)
            {
                if(!dfs(node, 1-cur_color))
                {
                    return false;
                }
            }
            else
            {
                if(cur_color == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
};