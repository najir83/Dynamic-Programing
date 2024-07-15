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
/*given a n items and their weight have value or you have given mx weight that you have to carry . return maximum value that u can stell*/
/*
// recursive solution
int recur = 0;
int mx_value(int i, vi &w, vi &v, int mx)
{
    recur++;
    if (mx == 0)
        return 0;
    if (i == 0)
    {
        return (w[0] <= mx ? v[0] : 0);
    }

    int p, np;
    p = np = 0;
    if (w[i] <= mx)
    {
        p = v[i] + mx_value(i - 1, w, v, mx - w[i]);
    }
    np = mx_value(i - 1, w, v, mx);
    return max(np, p);
}

// memo iozation
int mx_value(int i, vi &w, vi &v, int mx, vii &dp)
{
    if (mx == 0)
        return 0;
    if (i == 0)
    {
        return (w[0] <= mx ? v[0] : 0);
    }
    if (dp[i][mx] != -1)
        return dp[i][mx];

    int p, np;
    p = np = 0;
    if (w[i] <= mx)
    {
        p = v[i] + mx_value(i - 1, w, v, mx - w[i], dp);
    }
    np = mx_value(i - 1, w, v, mx, dp);
    return dp[i][mx] = max(np, p);
}
*/
// Tabulation

void tabu(int n, vi &w, vi &v, int range)
{
    vii dp(n, vi(range + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    for (int i = w[0]; i <= range; i++)
    {
        dp[0][i] = v[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= range; j++)
        {

            int p, np;
            p = np = 0;
            if (w[i] <= j)
            {
                p = v[i] + dp[i - 1][j - w[i]];
            }
            np = dp[i - 1][j];
            dp[i][j] = max(np, p);
        }
    }
    pnt(dp);
}
void print(vi &v)
{
    for (auto it : v)
        cout << it << " ";

    cout << endl;
}
void space_optimizing_dp(int n, vi &w, vi &v, int range)
{
    vi p(range + 1, 0), q(range + 1, 0);

    for (int i = w[0]; i <= range; i++)
    {
        p[i] = v[0];
    }
    print(p);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= range; j++)
        {

            int pk, np;
            pk = np = 0;
            if (w[i] <= j)
            {
                pk = v[i] + p[j - w[i]];
            }
            np = p[j];
            q[j] = max(pk, np);
        }
        p = q;
        print(p);
    }
}
void space_optimizing_dp2(int n, vi &w, vi &v, int range)
{
    /*
    in this case we are just doing in one array solution , so see if we do j:range to 1 
    then our not take and take will works fine.. is not that :)
    */
    vi p(range + 1, 0);

    for (int i = w[0]; i <= range; i++)
    {
        p[i] = v[0];
    }
    print(p);
    for (int i = 1; i < n; i++)
    {
        for (int j = range; j >=1; j--)
        {

            int pk, np;
            pk = np = 0;
            if (w[i] <= j)
            {
                pk = v[i] + p[j - w[i]];
            }
            np = p[j];
            p[j] = max(pk, np);
        }
      
        print(p);
    }
}
int main()
{
    int n = 3;
    vi w = {3, 2, 5};
    vi v = {30, 40, 60};
    int mx = 6;
    // cout << mx_value(n - 1, w, v, mx) << endl;
    // cout<<recur<<endl;
    // vii dp(n,vi(mx+1,-1));
    // cout<<mx_value(n-1,w,v,mx,dp)<<endl;;
    // pnt(dp);
    tabu(n, w, v, mx);
    space_optimizing_dp(n,w,v,mx);
    space_optimizing_dp2(n,w,v,mx); //*****
    return 0;
}