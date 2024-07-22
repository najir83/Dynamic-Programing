#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef float ff;
typedef vector<ll> vl;
typedef vector<vl> vll;
// int min_coins()
// {
// }
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
int c = 0;

int f(int i, vi &v, int tg)
{

    // cout<<i<<" "<<tg<<endl;
    if (tg == 0)
        return 0;
    if (i == 0)
    {
        return (tg % v[0] == 0 ? tg / v[0] : 1e8);
    }

    int p, np;
    p = np = 1e7;
    if (v[i] <= tg)
    {
        p = 1 + f(i, v, tg - v[i]);
    }
    np = f(i - 1, v, tg);

    return min(np, p);
}

int f(int i, vi &v, int tg, vii &dp)
{

    // cout<<i<<" "<<tg<<endl;
    // if (tg == 0)
    //     return 0;
    if (i == 0)
    {
        return (tg % v[0] == 0 ? tg / v[0] : 1e8);
    }
    if (dp[i][tg] != -1)
        return dp[i][tg];
    int p, np;
    p = np = 1e7;
    if (v[i] <= tg)
    {
        p = 1 + f(i, v, tg - v[i], dp);
    }
    np = f(i - 1, v, tg, dp);

    return dp[i][tg] = min(np, p);
}
void tabu(vi &v, int tg)
{
    int n = v.size();
    vii dp(n, vi(tg + 1, 1e7));
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= tg; i++)
    {
        if (i % v[0] == 0)
            dp[0][i] = i / v[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= tg; j++)
        {
            int p, np;
            p = np = 1e7;
            if (v[i] <= j)
            {
                p = 1 + dp[i][j - v[i]];
            }
            np = dp[i - 1][ j];

           dp[i][j] = min(np, p);
        }
    }
    pnt(dp);
}

int main()
{
    vi v = {1,2,3};
    int n = v.size();
    int tg = 7;
    // cout << f(n - 1, v, tg) << endl;

    // vii dp(n, vi(tg + 1, -1));
    // cout << f(n - 1, v, tg, dp) << endl;
    // pnt(dp);
    tabu(v,tg);
    return 0;
}