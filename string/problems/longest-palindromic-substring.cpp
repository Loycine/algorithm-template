#include <iostream>
#include <string>

using namespace std;


class BruteSolution {
public:
    string longestPalindrome(string s) {
        string ret;
        if(s=="")
        {
            ret = "";
            return ret;
        }
        
        int n = s.length();
        char ms[2*n+5];
        manacherStringGen(s.c_str(), ms, n);
        cout << ms << "\n";

        int maxPos;
        int maxR = -1;
        int curR;
        for(int i=0; i<=2*n; i++)
        {
            curR = bruteForce(ms,2*n+1,i);
            if(curR > maxR)
            {
                maxR = curR;
                maxPos = i;
            }
        }
        
        int left = (maxPos - maxR)/2;
        int len = maxR/2*2;
        if(maxR % 2)
        {
            len = len + 1;
        }
        return s.substr(left, len);       
    }
    
    
    void manacherStringGen(const char* s, char* ms, int n)
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
};

class ManacherSolution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        char ms[2*n + 2];
        manacherStringGen(s.c_str(),ms,n);
        
        int r[2*n + 1];
        int maxPos = manacher(ms, 2*n+1, r);

        int left = (maxPos-r[maxPos])/2;
        int len = r[maxPos]/2*2;
        if(maxPos % 2)
        {
            len++;
        }
        return s.substr(left, len);
    }
    
    
    void manacherStringGen(const char* s, char* ms, int n)
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
        int i = pos-bias;
        int j = pos+bias;
        int ret = 0;
        for(; i>=0&&j<n; i--, j++)
        {
            if(s[i] == s[j])
            {
                ret++;
            }
            else{
                return ret + bias - 1;
            }
        }
        return ret + bias - 1;
    }


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
                    int bias = iLeft - edgeL + 1;
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
};

int main()
{
    BruteSolution sln;
    string s;
    cin >> s;
    string ans;
    ans = sln.longestPalindrome(s);
    cout << ans << "\n";
}