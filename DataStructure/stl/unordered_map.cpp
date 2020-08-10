#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum[n+5];
        sum[0] = 0;
        for(int i=0; i<n; i++)
        {
            sum[i+1] = sum[i] + nums[i];
        }
        
        
        //sum[i] - sum[j] = k
        //sum[j] = sum[i] - k
        mp[0] = 1;
        for(int i=1; i<=n; i++)
        {
            auto it = mp.find(sum[i] - k);
            if(it != mp.end())
                ret += it->second;
            
            if(mp.find(sum[i]) != mp.end())
            {
                mp[sum[i]] ++;
            }else
            {
                mp[sum[i]] = 1;
            }
        }
        
        return ret;
    }
};

namespace Sum3
{
class Solution {
public:
    class Status{
    public:
        int x;
        int y;
        int z;
        
        Status(vector<int>& triplet)
        {
            x = triplet[0];
            y = triplet[1];
            z = triplet[2];
        }

        bool operator < (const Status& another)
        {
            if(x < another.x)
            {
                return true;
            }
            else
            {
                if(y < another.y)
                {
                    return true;
                }
                else
                {
                    return z < another.z;
                }
            }
        }
    };
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
    
            
        set<Status> mp;
            
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                for(int k=0; k<j; k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> triplet;
                        triplet.push_back(nums[i]);
                        triplet.push_back(nums[j]);
                        triplet.push_back(nums[k]);
                        sort(triplet.begin(),triplet.end());
                        Status s(triplet);
                        
                        if(mp.find(s) != mp.end()){
                            mp.insert(s);
                            ret.push_back(triplet);
                        }
                    }
                }
            }
        }
        return ret;
    }
};

}


int main()
{
    Sum3::Solution sln;
    vector<int> v  = {-1, 0, 1, 2, -1, -4};
    sln.threeSum(v);
    return 0;
}