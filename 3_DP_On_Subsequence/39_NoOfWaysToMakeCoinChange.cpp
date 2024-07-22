#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef float ff;
typedef vector<ll> vl;
typedef vector<vl> vll;
void pnt(vii v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (auto it : v[i])
            cout << it << " ";

        cout << endl;
    }
    cout << endl;
}
// recursive
int f(vi &v, int i, int tg)
{

    if (tg == 0)
        return 1;
    if (i == 0)
    {
        return (tg % v[i] == 0 ? 1 : 0);
    }

    int p = 0, np = 0;
    if (v[i] <= tg)
    {
        p = f(v, i, tg - v[i]);
    }
    np = f(v, i - 1, tg);
    return p + np;

    // Time complexity not (2^(n) its very very greater)
}

// memoiozation
int memo(vi &v, int i, int tg, vii &dp)
{

    if (tg == 0)
        return 1;
    if (i == 0)
    {
        return (tg % v[i] == 0 ? 1 : 0);
    }
    if (dp[i][tg] != -1)
        return dp[i][tg];

    int p = 0, np = 0;
    if (v[i] <= tg)
    {
        p = memo(v, i, tg - v[i], dp);
    }
    np = memo(v, i - 1, tg, dp);
    return dp[i][tg] = p + np;
    // Time complexity not (2^(n) its very very greater)
    // space O(n*tg)
}

// tabulation
void tabu(vi &v, int tg)
{
    int n = v.size();
    vii dp(n, vi(tg + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int i = 0; i <= tg; i++)
    {
        if (i % v[0] == 0)
            dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= tg; j++)
        {
            int p = 0, np = 0;
            if (v[i] <= j)
            {
                p = dp[i][j - v[i]];
            }
            np = dp[i - 1][j];
            dp[i][j] = p + np;
        }
    }
    pnt(dp);
}
int main()
{
    vi v = {1, 2, 3};
    int tg = 4;
    int n = v.size();
    // cout << f(v, n - 1, tg);

    vii dp(n, vi(tg + 1, -1));
    cout << memo(v, n - 1, tg, dp) << "\n";
    pnt(dp);
    tabu(v,tg);
    return 0;
}