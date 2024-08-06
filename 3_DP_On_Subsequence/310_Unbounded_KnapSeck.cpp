#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef float ff;
typedef vector<ll> vl;
typedef vector<vl> vll;
void pnt2d(vii &v)
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
int mx_value(int i, vi &v, vi &wt, int w)
{
    if (w == 0)
        return 0;
    if (i < 0)
        return 0;
    int ntake = 0, mtake = 0;
    if (wt[i] <= w)
    {
        mtake = v[i] + mx_value(i, v, wt, w - wt[i]);
    }
    ntake = mx_value(i - 1, v, wt, w);

    return max(ntake, mtake);

    // TC : >>O(2^n)
}
// memoiozation

int mx_value(int i, vi &v, vi &wt, int w, vii &dp)
{
    if (w == 0)
        return 0;
    if (i < 0)
        return 0;

    if (dp[i][w] != -1)
        return dp[i][w];
    int ntake = 0, mtake = 0;
    if (wt[i] <= w)
    {
        mtake = v[i] + mx_value(i, v, wt, w - wt[i], dp);
    }
    ntake = mx_value(i - 1, v, wt, w, dp);

    return dp[i][w] = max(ntake, mtake);

    // TC : >>O(2^n)
}

// tabulation
void tabu(vi &v, vi &wt, int w)
{
    int n = v.size();
    vii dp(n, vi(w + 1, 0));
    // pnt2d(dp);
    for (int i = 1; i <= w; i++)
    {

        dp[0][i] = (i / wt[0]) * v[0];
    }
    // pnt2d(dp);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int ntake = 0, mtake = 0;
            if (wt[i] <= j)
            {
                mtake = v[i] + dp[i][j - wt[i]];
            }
            ntake = dp[i - 1][j];

            dp[i][j] = max(ntake, mtake);
            // pnt2d(dp);
        }
    }
    pnt2d(dp);
}
// space optimization
void Space_OptimizingProcess(vi &v, vi &wt, int w)
{
    int n = v.size();
    vi p(w + 1, 0), q(w + 1, 0);
    // pnt2d(dp);
    for (int i = 1; i <= w; i++)
    {

        p[i] = (i / wt[0]) * v[0];
    }
    // pnt2d(dp);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int ntake = 0, mtake = 0;
            if (wt[i] <= j)
            {
                mtake = v[i] + q[j - wt[i]];
            }
            ntake = p[j];

            q[j] = max(ntake, mtake);
            // pnt2d(dp);
        }

        p = q;
    }
    for (auto it : p)
    {
        cout << it << " ";
    }
}

// One_Space

void Space_OneD(vi &v, vi &wt, int w)
{

    int n = v.size();
    vi p(w + 1, 0), q(w + 1, 0);
    for (int i = 1; i <= w; i++)
    {

        p[i] = (i / wt[0]) * v[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int ntake = 0, mtake = 0;
            ntake = p[j];
            if (wt[i] <= j)
            {
                mtake = v[i] + p[j - wt[i]];
            }

            p[j] = max(ntake, mtake);
        }

        // p = q;
    }
    for (auto it : p)
    {
        cout << it << " ";
    }
}

int main()
{
    // vi wt = {2, 4, 6};
    // vi v = {5, 11, 13};
    // int w = 10;
    int w = 3;
    vi v = {1, 1};
    vi wt = {2, 1};
    int n = v.size();
    // using recursion
    //  cout << mx_value(n - 1, v, wt, w);

    // using memoioxation
    // vii dp(n, vi(w + 1, -1));
    // mx_value(n - 1, v, wt, w, dp);
    // pnt2d(dp);

    tabu(v, wt, w);
    // Space_OptimizingProcess(v,wt,w);
    Space_OneD(v, wt, w);
    return 0;
}