#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef float ff;
typedef vector<ll> vl;
typedef vector<vl> vll;
/*bool recur(vi v, int i, int tg)

{
    if (tg == 0)
        return true;
    if (i < 0)
        return false;
    bool a = 0, b = 0;
    if (v[i] <= tg)
    {
        cout << v[i] << " " << tg << " " << i << endl;
        a = recur(v, i - 1, tg - v[i]);
    }
    b = recur(v, i - 1, tg);
    return (a or b);
}
bool dpp(vi v, int i, int tg, vector<vector<int>> &dp)
{
    if (tg == 0)
        return true;
    if (i < 0)
        return false;
    if (dp[i][tg] != -1)
        return dp[i][tg];
    bool a = 0, b = 0;
    if (v[i] <= tg)
    {
        //cout << v[i] << " " << tg << " " << i << endl;
        a = dpp(v, i - 1, tg - v[i], dp);
    }
    b = dpp(v, i - 1, tg, dp);
    return dp[i][tg] = (a or b);
}
void subset(vi v, int k)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(k, -1));
    cout<<dpp(v,n-1,k,dp);
    //TC O(N x tg)
}
*/
void pnt(vector<vector<bool>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (auto it : v[i])
            cout << it << " ";

        cout << endl;
    }
    cout << endl;
}
void Trabulation(vi v, int k)
{
    int n = v.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    // base case 1
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    // base case 2
    if (v[0] <= k)
        dp[0][v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool a = 0, b = 0;
            if (v[i] <= j)
            {
                // cout << v[i] << " " << tg << " " << i << endl;
                a = dp[i - 1][j - v[i]];
            }
            b = dp[i - 1][j];
            dp[i][j] = (a or b);
        }
    }
    pnt(dp);
    cout << dp[n - 1][k] << endl;
}

void space_optimization(vi v, int k)
{
    int n = v.size();
    vector<bool> tem(k + 1, false), t2(k + 1, false);
    tem[0] = 1;
    tem[v[0]] = 1;
    t2[0]=1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool nt = tem[j], t = 0;
            if (j >= v[i])
            {
                t = tem[j - v[i]];
            }
            t2[j] = (t or nt);
        }
        tem = t2;
    }
    cout << tem[k] << endl;
}
int main()
{
    vi v = {2,3,1,1,5,3};
    // cout << recur(v, v.size() - 1, 7);
    // subset(v,4);
     Trabulation(v, 1);
    space_optimization(v, 4);
    return 0;
}