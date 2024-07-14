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

// Divide into two parts where sum dif. between them is minimum
void Tabu(vi &v)
{
    int n = v.size();
    int s = accumulate(v.begin(), v.end(), 0);
    int x = s;
    s /= 2;
    vii dp(n, vi(s + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (v[0] <= s)
        dp[0][v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= s; j++)
        {

            int p = 0, np = 0;
            if (v[i] <= j)
            {
                p = dp[i - 1][j - v[i]];
            }
            np = dp[i - 1][j];
            dp[i][j] = (p or np);
        }
    }
    pnt(dp);
    for (int tg = s; tg >= 0; tg--)
    {
        if (dp[n - 1][tg])
        {
            cout << tg << " " << x - tg << endl;
            break;
        }
    }
}
void Space_Optimization(vi v)
{
    int n = v.size();
    int sm = accumulate(v.begin(), v.end(), 0);
    int x = sm;
    sm = x / 2;
    if (sm == -1)
        return;

    vector<bool> p(sm + 1, false), q(sm + 1, false);
    p[v[0]] = 1;
    p[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= sm; s++)
        {
            q[s] = (p[s] or ((v[i] <= s) ? p[s - v[i]] : 0));
        }
        p = q;
        for (int i = 0; i <= sm; i++)
            q[i] = 0;

        q[0] = 1;
    }
    for (int tg = sm; tg >= 0; tg--)
    {
        if (p[tg])
        {
            cout << tg << " " << x - tg << endl;
            break;
        }
    }
}

int main()
{
    vi v = {1, 3, 4, 3, 2, 3, 4, 6, 3, 6, 7, 7, 7, 7, 2, 5, 6};
    Tabu(v);
    Space_Optimization(v);
    return 0;
}