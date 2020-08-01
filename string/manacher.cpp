#include <iostream>
#include <cstdio>

#include <string>
#include <algorithm>
using namespace std;


void manacherStringGenerate(const char* s, char* ms, int n)
{
    for(int i=0; i<n; i++)
    {
        ms[2 * i] = '#';
        ms[2*i+1] = s[i];
    }
    ms[2*n]='#';
    ms[2*n+1] = '\0';
}

int bruteForce(const char* s, int n, int pos)
{
    int i = pos-1;
    int j = pos+1;
    int ret = 0;
    for(; i>=0&&j<n; i--, j++)
    {
        if(s[i] == s[j])
        {
            ret++;
        }
        else{
            return ret;
        }
    }
    return ret;
}

int bruteForceWithBias(const char* s, int n, int pos, int bias)
{
    int i = pos-bias-1;
    int j = pos+bias+1;
    int ret = bias;
    for(; i>=0&&j<n; i--, j++)
    {
        if(s[i] == s[j])
        {
            ret++;
        }
        else{
            return ret;
        }
    }
    return ret;
}


/*
Manacher: Find the longest 回文串 in String s.
Step1: 原来的String首尾和间隔填充'#'字符，解决aa和aba问题。
babadadaw
#b#a#b#a#d#a#d#a#w#

Step2: Update回文半径数组，最右边界

      |--r-|-r--|
      (    c    ) 
#b#a#b#a#d#a#d#a#w#
         i'  i

1> 当前位置不在最右边界内，暴力扩bruteForce
2> 当前位置在最右边界内
    2.1> 对称点的半径完全在左边界内，回文半径=对称点 
    2.2> 对称点的半径超过左边界，回文半径=对称点-左边界
    2.3> 对称点的半径恰好在左边界上，从右边界开始暴力扩 bruteForceWithBias

Step3: 对应回原来的位置
Find max radius r and it's center c.
Then original substring's left and len is:
left = (c-r)/2
len = r/2*2 + (center%2)
*/

int manacher(char* s, int n, int r[])
{
    int maxR = -1;
    int maxPos;

    int edgeR = -1;
    int edgeL = -1;
    int center = 0;

    for(int i=0; i<n; i++)
    {
        int curR;
        if(i>edgeR)
        {
            curR = bruteForce(s, n, i);
        }
        else //if(i<=edgeR)
        {
            int iLeft = 2*center-i;
            int iLeftEdgeLeft = iLeft - r[iLeft];
            if(iLeftEdgeLeft > edgeL)
            {
                curR = r[iLeft];
            }
            else if(iLeftEdgeLeft < edgeL)
            {
                curR = iLeft - edgeL;
            }
            else //if(iLeftEdgeLeft == edgeL)
            {
                int bias = iLeft - edgeL;
                curR = bruteForceWithBias(s, n, i, bias);
            }
        }


        r[i] = curR;
        if(i+curR > edgeR)
        {
            edgeR = i + curR;
            edgeL = i - curR;
            center = i;
        }
        if(curR > maxR)
        {
            maxR = curR;
            maxPos = i;
        }
        if(edgeR == n-1)
        {
            return maxPos;
        }
    }
    return maxPos;
}



string s;

const int maxn = 1e5+5;
int r[maxn];
int right;

int main()
{
    cin >> s;
    int n = s.length();
    char ms[2*n + 5];
    manacherStringGenerate(s.c_str(),ms,n);
    int r[2*n + 5];
    int maxPos = manacher(ms, 2*n+1, r);
    
    int left = (maxPos-r[maxPos])/2;
    int len = r[maxPos]/2*2;
    if(maxPos % 2)
    {
        len++;
    }
    cout << left << " " << len << "\n";
    cout << s.substr(left, len) << "\n";
}