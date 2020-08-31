#include <iostream>
#include <vector>
#include <map>

using namespace std;



namespace simulation{

class MajorityChecker {
public:
    vector<int> a;
    MajorityChecker(vector<int>& arr) {
        a = arr;
    }
    
    map<pair<int, int>, pair<int,int> > mp;
    int query(int left, int right, int threshold) {
        auto it = mp.find(make_pair(left, right));
        if(it != mp.end())
        {
            int cnt = it->second.first;
            int val = it->second.second;
            return cnt >= threshold? val : -1;
        }

        int cnt = 0;
        int val = -1;

        for(int i=left; i<=right; i++) {
            if(cnt == 0)
            {
                cnt ++;
                val = a[i];
            }
            else {
                val==a[i]?cnt++:cnt--;
            }
        }

        cnt = 0;
        for(int i=left; i<=right; i++) {
            if(a[i] == val)
            {
                cnt ++;
            }
        }
        mp[make_pair(left, right)] = make_pair(cnt,val);
        return cnt >= threshold? val : -1;
    }
};

};


#include <ctime>
#include <algorithm>

class MajorityChecker {
public:
    map<int, vector<int> > mp;
    vector<int> arr;
    MajorityChecker(vector<int>& arr) : arr(arr){
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = vector<int>(1, i);
            }
            else {
                mp[arr[i]].push_back(i);
            }
        }
        srand(time(NULL));
    }
    
    int query(int left, int right, int threshold) {

        for(int times = 0; times < 20; times ++)
        {
            int pos = rand()%(right + 1 - left) + left;
            int val = arr[pos];
            auto& v = mp[val];

            int firstIndex = lower_bound(v.begin(), v.end(), left) - v.begin();
            int lastIndex = upper_bound(v.begin(), v.end(), right) - v.begin();

            if(lastIndex - firstIndex > threshold) {
                return val;
            }

        }
        return -1;
    }
};



int main()
{
    return 0;
}
