#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) {
            return {-1, -1};
        }

        //lower_bound
        int l = 0; 
        int r = nums.size();
        while(r-l >= 1) {
            int mid = (l + r) / 2;
            if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        if(l >= nums.size() || nums[l] != target) {
            return {-1, -1};
        }
        int left = l;

        //upper_bound
        l = 0; 
        r = nums.size();
        while(r-l >= 1) {
            int mid = (l + r ) / 2;
            if(nums[mid] > target) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        l--;
        
        return {left, l};
    }
};