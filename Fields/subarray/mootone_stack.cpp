#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        A.push_back(0);
        
        int M = 1e9 + 7;
        
        int ret = 0;
        stack<pair<int,int> > s;
        int n = A.size();
        s.push(make_pair(-1, -1));
        for(int i=0; i<n; i++)
        {

            while(!s.empty() && A[i] < s.top().first)
            {
                auto cur = s.top();
                s.pop();

                int v = cur.first;

                int position = cur.second;
                int left = s.top().second;
                int right = i;

                ret = (position - left)*(right-position)*v % M + ret;
                ret %= M;
            }
            
            s.push(make_pair(A[i], i));

        }
        return (int)ret;
    }
};

int main()
{
    Solution sln;
    vector<int> A = {3,1,2,4};
    cout << sln.sumSubarrayMins(A) << "\n";
}