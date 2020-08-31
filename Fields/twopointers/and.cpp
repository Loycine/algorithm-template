#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


const int m = 24;


namespace version1{

class Solution {
public:
    void add(int x, int& sum, vector<int>& cnt) {
        for(int i=0; i<m; i++)
        {
            if(!(x >> i & 1))
            {
                cnt[i] ++;
                if(cnt[i] == 1)
                {
                    sum |= 1 << i;
                    sum ^= 1 << i;
                }
            }
        }
    }

    void remove(int x, int& sum, vector<int>& cnt) {
        for(int i=0; i<m ;i++)
        {
            if(!(x >> i & 1))
            {
                cnt[i] --;
                if(cnt[i] == 0)
                {
                    sum |= 1 << i;
                }
            }
        }
    }

    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();

        int l;
        int r;

        vector<int> cnt(m, 0);

        int sum = (1 << m) - 1;

        int ans = abs(target - arr[0]);

        for(l=0, r=0; r<n; r++) {
            add(arr[r], sum, cnt);
            ans = min(ans, abs(target - sum));

            while(sum <= target && l < r ) {
                remove(arr[l++], sum, cnt);
                ans = min(ans, abs(target - sum));
            }
        }
        
        return ans;
    }
};

};


class Solution {
public:
    void add(int x, int& sum, vector<int>& cnt) {
        sum = 0;
        for(int i=0; i<m; i++)
        {
            if(!(x >> i & 1))
            {
                cnt[i] ++;
            }
            if(cnt[i] == 0)
            {
                sum |= (1 << i);
            }
        }
    }

    void remove(int x, int& sum, vector<int>& cnt) {
        sum = 0;
        for(int i=0; i<m ;i++)
        {
            if(!(x >> i & 1))
            {
                cnt[i] --;
            }
            if(cnt[i] == 0)
            {
                sum |= (1 << i);
            }
        }
    }

    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();

        int l;
        int r;

        vector<int> cnt(m, 0);

        int sum = (1 << m) - 1;

        int ans = abs(target - arr[0]);

        for(l=0, r=0; r<n; r++) {
            add(arr[r], sum, cnt);
            ans = min(ans, abs(target - sum));

            while(sum <= target && l < r ) {
                remove(arr[l++], sum, cnt);
                ans = min(ans, abs(target - sum));
            }
        }
        
        return ans;
    }
};