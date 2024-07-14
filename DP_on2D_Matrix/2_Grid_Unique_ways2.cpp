#include <bits/stdc++.h>
using namespace std;
using vc = vector<vector<int>>;
void print(vc v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (auto it : v[i])
            cout << it << " ";

        cout << endl;
    }
    cout << endl;
}
// recursion for make it dp
int numberOFways(int i, int j, int d1, int d2)
{
    if (i == d1 && j == d2)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    else
        return numberOFways(i, j - 1, d1, d2) + numberOFways(i - 1, j, d1, d2);
}
// memo iozation
int cnt = 1;
;
int numberOFways2(int i, int j, vc &dp, int d1, int d2)
{
   
    if (i == d1 && j == d2)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    else

        return dp[i][j] = ((numberOFways2(i, j - 1, dp, d1, d2)) + (numberOFways2(i - 1, j, dp, d1, d2)));
}
//tabulation
int numberOFways3(int n, int m,int a,int b)
{
    vc dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = 1;
    }
    dp[a][b]=0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(i==a && j==b)continue;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    print(dp);

    return dp[n - 1][m - 1];
}
int main()
{
    int n = 10, m = 10;
    vc dp(n, vector<int>(m, -1));
   // cout << "\nNumbers of ways : " << numberOFways(n - 1, m - 1, 1, 1);
    cout << "\nNumbers of ways : " << numberOFways2(n - 1, m - 1, dp, 7, 4);
   numberOFways3(n,m,7,4);
    return 0;
}