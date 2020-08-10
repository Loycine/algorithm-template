#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

//Rank Tree
template<class T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
Note on using less_equal as comparison function to use it as a multiset:

_GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
find will always return end.
lower_bound works like upper_bound in normal set (to return the first element > it)
upper_bound works like lower_bound in normal set (to return the first element >= it)
find_by_order and order_of_key works properly (unlike the 2 functions above).

So if you want to erase, please use erase(upper_bound(k)) or erase(r = order_of_key(k) and find_by_order(r)).
*/
template<class T> using ordered_multiset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;



namespace medianSlidingWindow{
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        ordered_multiset<int> tree;
        vector<double> ret;
        int n = nums.size();
        if(n == 0)
        {
            return ret;
        }
        for(int i=0; i<k; i++)
        {
            tree.insert(nums[i]);
        }
        if(k%2)
        {
            int median = *tree.find_by_order(k/2);
            ret.push_back(median);
            for(int i=k; i<n; i++)
            {      
                tree.erase(tree.upper_bound(nums[i-k]));
                tree.insert(nums[i]);
                int median = *tree.find_by_order(k/2);
                ret.push_back(median);
            }
        }
        else{
            double median = ((double)*tree.find_by_order(k/2) + (double)*tree.find_by_order(k/2-1))/2.0;
            ret.push_back(median);
            for(int i=k; i<n; i++)
            {
                tree.erase(tree.upper_bound(nums[i-k]));
                tree.insert(nums[i]);
                double median = (double)((double)*tree.find_by_order(k/2) + (double)*tree.find_by_order(k/2-1))/2.0;
            ret.push_back(median);
            }
        }
        return ret;
    }
};
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    ordered_multiset<int> tree;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        tree.insert(num);
    }
    
    double findMedian() {
        int n = tree.size();
        if(n == 0)
        {
            return 0;
        }
        double ret;
        if(n%2)
        {
            ret = *tree.find_by_order(n/2);
        }
        else {
            ret = (double)*tree.find_by_order(n/2) + (double)*tree.find_by_order(n/2-1);
        }
        return ret;
    }
};
