#include <bits/stdc++.h>
using namespace std;
using vc = vector<int>;
int cnt = 0;
void print(vector<vc> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (auto it : v[i])
            cout << it << " ";

        cout << endl;
    }
}
int mx(vector<vc> v, int i, int pre)
{
    if (i < 0)
        return 0;

    int val = 0;
    for (int j = 0; j < 3; j++)
    {
        if (j == pre)
            continue;
        val = max(val, v[i][j] + mx(v, i - 1, j));
        cout << cnt++ << "Func call .." << endl;
    }
    // TC : O(2^n);
    return val;
}
// memo TC=O(3N) SC(2N)
int mx2(vector<vc> v, int i, int pre, vector<vc> &dp)
{
    if (i == v.size())
        return 0;

    int val = 0;
    for (int j = 0; j < 3; j++)
    {

        if (j == pre)
            continue;
        if (dp[i][j] == -1)
        {
            dp[i][j] = v[i][j] + mx2(v, i + 1, j, dp);
            cout << "call ";
        }

        val = max(val, dp[i][j]);
    }
    return val;
}
// Trabulation TC=O(9N) SC=(3N)

void mx3(vector<vc> v)
{
    vector<vector<int>> dp(v.size(), vector<int>(3, 0));
    int val = 0;
    int ans = 0;
    for (int i = 0; i < 3; i++)
        dp[0][i] = v[0][i];
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = v[i][j];

            int val = 0;
            for (int k = 0; k < 3; k++)
            {
                if (i - 1 < 0 || k == j)
                    continue;

                val = max(val, dp[i - 1][k]);
            }
            dp[i][j] += val;
            ans = max(ans, dp[i][j]);
        }
    }
    print(dp);
    cout << "Maximun Point 2 : " << ans;
}
// Memori Optimization TC=O(9N)
void pnt(vc v)
{
    for (auto it : v)
        cout << it << " ";

    cout << endl;
}
void mx4(vector<vc> v)
{
    vector<int> p(3, 0), q(3, 0);
    int val = 0;
    int ans = 0;
    for (int i = 0; i < 3; i++)
        p[i] = v[0][i], ans = max(ans, p[i]);

    pnt(p);
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            q[j] = v[i][j];

            int val = 0;
            for (int k = 0; k < 3; k++)
            {
                if (k == j)
                    continue;

                val = max(val, p[k]);
            }

            q[j] += val;
            ans = max(ans, q[j]);
        }
        pnt(q);
        p = q;
    }
    cout << "Maximun Point 2 : " << ans;
}

void Ninja_Training(vector<vc> v)
{
    // cout << "Maximun Point : " << mx(v, v.size() - 1, -1) << endl;

    vector<vector<int>> dp(v.size(), vector<int>(3, -1));
    cnt = 0;
    cout << "Maximun Point 2 : " << mx2(v, 0, -1, dp) << endl;

    print(dp);
}

int main()
{
    vector<vc> v = //{{10, 50, 1}, {5, 100, 11}};
        {{1, 2, 5}, {1, 1, 1}, {3, 3, 3}};
    // Ninja_Training(v);
    mx4(v);
    return 0;
}