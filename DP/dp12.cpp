#include <bits/stdc++.h>
using namespace std;

int n,m;
const int maxn = 1e3 + 5;

int a[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {
            if(i == n-1 && j == m-1) {
                dp[i][j] = max(1, -a[i][j]+1);
            }
            else if(i == n-1) {
                dp[i][j] = max(dp[i][j+1] - a[i][j], 1);
            }
            else if(j == m-1) {
                dp[i][j] = max(dp[i+1][j] - a[i][j], 1);
            }
            else {
                dp[i][j] = min(dp[i+1][j] - a[i][j], dp[i][j+1] - a[i][j]);
                dp[i][j] = max(1, dp[i][j]);
            }
        }
    }
    printf("%d\n", dp[0][0]);
}
