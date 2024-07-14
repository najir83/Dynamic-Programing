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

// Minimum path sum in a triangle . where you can move from i,j to i+1m=,j or i+1,j+1
// recursion
//  TC = O(2^n)
int recur(vc v, int i, int j, int m)
{
    if (i == m - 1)
        return v[i][j];
    // if(j>=v[i].size())return 1e7;
    else
    {
        int d = recur(v, i + 1, j, m);
        int r = recur(v, i + 1, j + 1, m);
        return v[i][j] + min(d, r);
    }
}
/*
// memoiozation TC= O(N)
int memo(vc v, int i, int j, int m, vc &dp)
{
    if (i == m - 1)
        return v[i][j];
    // if(j>=v[i].size())return 1e7;
    else if (dp[i][j] != -1)
        return dp[i][j];
    else
    {
        int d = memo(v, i + 1, j, m, dp);
        int r = memo(v, i + 1, j + 1, m, dp);
        return dp[i][j] = v[i][j] + min(d, r);
    }
}*/
// // Tabulation TC : O(nXm) and SC : O(nXm)
// void tabu(vc v)
// {
//     vc dp(v.size(), vector<int>());
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             dp[i].push_back(-1);
//         }
//     }
//     dp[0][0] = v[0][0];
//     int ans = 1e9;
//     for (int i = 1; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             int up_left = (j - 1 >= 0) ? dp[i - 1][j - 1] : 1e5;
//             int up = dp[i - 1][j];
//             dp[i][j] = v[i][j] + min(up, up_left);
//             if (i == v.size() - 1)
//                 ans = min(ans, dp[i][j]);
//         }
//     }

//     print(dp);
// }

// memory optimization TC=O(nxm)
void pnt(vector<int> v)
{
    for (auto it : v)
        cout << it << " ";

    cout << endl;
}
void mem_optimazation(vc v)
{
    int n = v.size();
    vector<int> p(v[n - 1].size(), 1e7), q(v[n - 1].size(), 1e7);
    p[0] = v[0][0];
    for (int i = 1; i < n; i++)
    {  pnt(p);
        for (int j = 0; j < v[i].size(); j++)
        {
            int up_left = (j >0) ? p[j - 1] : 1e5;
            int up = p[j];
            q[j] = v[i][j] + min(up_left, up);
        }
       
        p = q;
    }
     pnt(q);
}

int main()
{
    vc v = {{1},
            {4, 3},
            {3, 4, 7},
            {7, 9, 11, 10}};

    print(v);
    cout << "Recursive answer " << recur(v, 0, 0, v.size()) << endl;
    /*
       vc dp(v.size(), vector<int>());
       for (int i = 0; i < v.size(); i++)
       {
           for (int j = 0; j < v[i].size(); j++)
           {
               dp[i].push_back(-1);
           }
       }
       cout << "Memo answer " << memo(v, 0, 0, v.size(), dp) << endl;
       print(dp);*/

    // tabu(v);
mem_optimazation(v);
    return 0;
}