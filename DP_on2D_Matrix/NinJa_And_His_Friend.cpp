#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef float ff;
typedef vector<ll> vl;
typedef vector<vl> vll;

int f(int i, int j1, int j2, vii a, int n, int m)
{
    if (j1 < 0 or j1 >= m or j2 < 0 or j2 >= m or i >= n)
        return -1e8;
    if (i == n - 1)
    {
        return (a[i][j1] != a[i][j2] ? a[i][j1] + a[i][j2] : a[i][j1]);
    }

    int mxi = 0;
    for (int j = -1; j <= 1; j++)
    {
        for (int k = -1; k <= 1; k++)
        {
            int x = f(i + 1, j1 + j, j2 + k, a, n, m);
            if (j1 == j2)
            {
                mxi = max(a[i][j1] + x, mxi);
            }
            else
                mxi = max(a[i][j1] + a[i][j2] + x, mxi);
        }
    }
    return mxi;
} // TC : O(9^n)  SC:O(n) .. axilary stack place

int f_dp(int i, int j1, int j2, vii a, int n, int m, vector<vii> &dp)
{
    if (j1 < 0 or j1 >= m or j2 < 0 or j2 >= m or i >= n)
        return -1e8;
    if (i == n - 1)
    {
        return (a[i][j1] != a[i][j2] ? a[i][j1] + a[i][j2] : a[i][j1]);
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int mxi = 0;
    for (int j = -1; j <= 1; j++)
    {
        for (int k = -1; k <= 1; k++)
        {
            int x = f_dp(i + 1, j1 + j, j2 + k, a, n, m, dp);
            if (j1 == j2)
            {
                mxi = max(a[i][j1] + x, mxi);
            }
            else
                mxi = max(a[i][j1] + a[i][j2] + x, mxi);
        }
    }
    return dp[i][j1][j2] = mxi;
} // TC : O(n x m x m)*9 SC : O(n+n X m X m)


int main()
{
    vii ninja = {{2, 3, 1, 2},
                 {3, 4, 2, 2},
                 {5, 6, 3, 5}};
    int n = ninja.size();
    int m = ninja[0].size();
    // vector<vii> dp(n, vii(m, vi(m, -1)));
    // // cout<<"Ans will be "<<f(0,0,m-1,ninja,n,m)<<endl;
    //  cout<<"Ans will be "<<f_dp(0,0,m-1,ninja,n,m,dp)<<endl;
    return 0;
}