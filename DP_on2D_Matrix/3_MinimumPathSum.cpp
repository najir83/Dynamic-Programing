#include <bits/stdc++.h>
using namespace std;
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
// minimum path sum .. given a 2d .. you can go right and left . return minimum path sum from 0,0 to n-1,m-1
int minimumPathSum(vc v, int i, int j)
{
    if (i < 0 || j < 0)
        return 1000;
    if (i == 0 and j == 0)
        return v[0][0];
    else
    {
        int l = minimumPathSum(v, i - 1, j);
        int u = minimumPathSum(v, i, j - 1);
        return v[i][j] + min(l, u);
    }
}

// memoiozation
int memo(vc v, int i, int j, vc &dp)
{
    if (i < 0 || j < 0)
        return 1000;
    if (i == 0 and j == 0)
    {

        return v[0][0];
    }
    else if (dp[i][j] != -1)
        return dp[i][j];
    else
    {
        int l = memo(v, i - 1, j, dp);
        int u = memo(v, i, j - 1, dp);
        return dp[i][j] = v[i][j] + min(l, u);
    }
}
// Tabulation
int tabu(vc v, int n, int m)
{
    vc dp(n, vector<int>(m, 0));
    dp[0][0] = v[0][0];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                continue;

            int r = 1000, d = 1000;
            if (i - 1 >= 0)
                d = dp[i - 1][j];
            if (j - 1 >= 0)
                r = dp[i][j - 1];

            dp[i][j] = v[i][j] + min(d, r);
        }
        print(dp);
    }
    print(dp);
    return 0;
}
// space optimization
void pnt(vector<int>v){
    for(auto it:v)cout<<it<<" ";

    cout<<endl;
}
void ans(vc v, int n, int m)
{
    vector<int> dp(m, 0);
    dp[0] = v[0][0];
    for (int i = 0; i < n; i++)
    {
        int pre = 1000000000;
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
            {
                pre = dp[0];
                continue;
            }
            int l = pre;
            int u = 100000000;
            if (i > 0)
            {
                u = dp[j];
            }
            dp[j] = v[i][j] + min(u, l);
            pre = dp[j];
        }
    }
    pnt(dp);
    
}
int main()
{
    vc v2 = {{100, 100, 100},
             {100, 100, 100},
             {100, 100, 100},
             
             {100, 100, 100}};
             
    // vc v2 = {{5, 9, 6},
    //          {11, 5, 2}};
    int n = v2.size();
    int m = v2[0].size();
    // using recursion
    // cout << "ans will be " << minimumPathSum(v2, n - 1, m - 1) << endl;

    // // memo
    // vc dp(n, vector<int>(m, -1));
    // cout << "ans will be " << memo(v2, n - 1, m - 1, dp) << endl;
    // print(dp);
    //tabu(v2, n, m);
   ans(v2,n,m);
 
   
    return 0;
}