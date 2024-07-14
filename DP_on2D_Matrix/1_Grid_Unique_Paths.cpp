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
// given nxm matrix .. return no. of ways to reached n-1,m-1

// void ways(int i, int j, int n, int m, int &cnt, vc v)
// {

//     v[i][j] = 1;
//     if (i == n - 1 && j == m - 1)
//     {
//         cnt++;
//         print(v);
//         v[i][j] = 0;
//         return;
//     }
//     if (i + 1 < n)
//     {

//         ways(i + 1, j, n, m, cnt, v);
//     }
//     if (j + 1 < m)
//     {
//         ways(i, j + 1, n, m, cnt, v);
//     }
//     v[i][j] = 0;
// }
// recursion for make it dp
// int numberOFways(int i, int j)
// {
//     if (i == 0 && j == 0)
//         return 1;
//     if (i < 0 || j < 0)
//         return 0;
//     else
//         return numberOFways(i, j - 1) + numberOFways(i - 1, j);
// }
// memo iozation
int md = 2000;
int numberOFways2(int i, int j, vc &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    else

        return dp[i][j] = ((numberOFways2(i, j - 1, dp)) + (numberOFways2(i - 1, j, dp)));
}
// Tabullation
int numberOFways(int n, int m)
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
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    print(dp);

    return dp[n - 1][m - 1];
}

// space optimization
void ans(int n, int m)
{
    vector<int> v(n, 1);
 int ans=1;
    for (int j = 1; j < m; j++)
    {
        int pre = 1;
        for (int i = 1; i < n; i++)
        {
            v[i] = v[i] + pre;
            pre = v[i];
           // cout << pre <<" ";
           pre%=10000;
           ans=pre;
        }
    }
    cout<<"ans "<<ans<<endl;
}

int main()
{
    int cnt = 0;
    int n = 50, m = 50;
    // vc v(n, vector<int>(m, 0));
    // ways(0, 0, n, m, cnt, v);
    // cout << "Number of ways " << numberOFways(n - 1, m - 1)<<endl;

    // call tabu
    //cout << "Number of ways " << numberOFways(n, m) << endl;
    // memo calls

    // vc dp(n, vector<int>(m, -1));
    // cout << "Number of ways " << numberOFways2(n - 1, m - 1, dp);
    // print(dp);

    ans(n, m);
    return 0;
}