#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef float ff;
typedef vector<ll> vl;
typedef vector<vl> vll;
void pnt(vii &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (auto it : v[i])
            cout << it << " ";

        cout << endl;
    }
    cout << endl;
}
// recursive solution
int x = 0;
/*int f(int i, vi &v, int tg)
{
    x++;

    if (tg == 0)
        return 1;
    if (i == 0)
        return v[0] == tg;

    int pick, notPick;
    pick = notPick = 0;
    pick = (v[i] <= tg ? f(i - 1, v, tg - v[i]) : 0);
    notPick = f(i - 1, v, tg);
    return pick + notPick;
}
// memo iozation

int f(int i, vi &v, int tg, vii &dp)
{
    x++;

    if (tg == 0)
        return 1;
    if (i == 0)
        return v[0] == tg;
    if (dp[i][tg] != -1)
        return dp[i][tg];
    int pick, notPick;
    pick = notPick = 0;
    pick = (v[i] <= tg ? f(i - 1, v, tg - v[i],dp) : 0);
    notPick = f(i - 1, v, tg,dp);
    return dp[i][tg] = pick + notPick;
}
*/
void tabu(vi v, int k)
{
    int n = v.size();
    vii dp(n, vi(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (v[0] <= k)
        dp[0][v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int pick, notPick;
            pick = notPick = 0;
            pick = (v[i] <= j ? dp[i - 1][j - v[i]] : 0);
            notPick = dp[i - 1][j];
            dp[i][j] = pick + notPick;
        }
    }
    pnt(dp);
}
// space optimization
void space_optimizing_tabu(vi v, int k)
{
    int n = v.size();
    vi p(k + 1, 0), q(k + 1, 0);
    p[0] = 1;

    if (v[0] <= k)
        p[v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
            q[j] = 0;

        for (int j = 1; j <= k; j++)
        {
            int pick, notPick;
            pick = notPick = 0;
            pick = (v[i] <= j ? p[j - v[i]] : 0);
            notPick = p[j];
            q[j] = pick + notPick;
        }
        swap(p, q);

        p[0] = 1;
    }
    for (auto it : p)
    {
        cout << it << " ";
    }
    cout << "\n";
}
int main()
{
    vi v = {1, 2, 2, 3};
    int k = 3;
    int n = v.size();
    // cout << f(v.size() - 1, v, 2) << endl;
    /* cout << x << endl;

     x = 0;
     vii dp(n, vi(k + 1, -1));
     cout << f(n - 1, v, k, dp) << endl;
     pnt(dp);
     cout << x << endl;
     */
    // tabulation
    // tabu(v, 3);
    space_optimizing_tabu(v, k);
    return 0;
}