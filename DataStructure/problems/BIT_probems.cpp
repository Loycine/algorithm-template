#include "../BIT.cpp"

//BIT
namespace Leetcode493
{
struct node
{
    long long x;
    int position;
    bool original;
    
    node(long long x1, int x2, bool x3)
    {
        x = x1;
        position = x2;
        original = x3;
    }

    node()
    {

    }
};

bool cmp(const node& a, const node& b)
{
    if(a.x == b.x)
    {
        return a.position > b.position;
    }
    else
    {
        return a.x < b.x;
    }
}

class Solution {
public:
    BIT bit;
    
    int reversePairs(vector<int>& nums) {
        int ret = 0;
        
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        
        bit.init(n);
        
        vector<node> v;
        for(int i=0; i<n; i++)
        {
            v.push_back( node(nums[i], i, true) );
            v.push_back( node(2LL * nums[i], i, false) );
        }
        
        sort(v.begin(), v.end(), cmp);
        
        for(int i=0; i<2*n; i++)
        {
            //cout << v[i].x << " " << v[i].position << "  ";
            if(v[i].original)
            {
                ret += bit.sum(v[i].position);
            }
            else {
                bit.add(v[i].position+1, 1);
            }
            //cout << ret << "\n";
        }
        
        return ret;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {2,22,23,3,7,16,25,11,18,19,4,11,1,25,22,9,11,14,9,3,16,8,5,11,12,15,15,19,15,15,7,17,24,18,9,8,20,23,18,17,7};
    cout << sln.reversePairs(nums) << "\n";
    return 0;
}
};


//BIT2D

namespace POJ2155{
int X;
int N, T;
int Q, x, y;
int C, x1, yy1,x2,y2;

char I;
int main()
{   
    scanf("%d", &X);
    BIT2D bit;
    while(X--)
    {
        scanf("%d%d", &N, &T);
        bit.init(N);


        while(T--)
        {
            getchar();
            scanf("%c", &I);
            if(I == 'C')
            {
                scanf("%d%d%d%d", &x1, &yy1, &x2, &y2);
                bit.add(x1, yy1, 1);
                bit.add(x1, y2+1, 1);
                bit.add(x2+1, yy1, 1);
                bit.add(x2+1, y2+1 ,1);
            }
            else if(I == 'Q')
            {
                scanf("%d%d",&x, &y);
                printf("%d\n", (bit.sum(x, y)%2));
            }
        }

        printf("\n");
    }

    return 0;
}
};

namespace POJ1195{
int I;
int S;
int X, Y, A;
int L,B,R,T;

int main()
{
    BIT2D bit;
    
    scanf("%d%d", &I, &S);
    bit.init(S);
    while(scanf("%d", &I)!=EOF)
    {
        if(I == 3)
        {
            return 0;
        }
        else if(I == 1)
        {
            scanf("%d%d%d", &X, &Y, &A);
            bit.add(X+1, Y+1, A);
        }
        else if(I == 2)
        {
            scanf("%d%d%d%d", &L, &B, &R, &T);
            printf("%d\n",bit.query(L+1, B+1, R+1, T+1));
        }
    }
    return 0;
}
};
