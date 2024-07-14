#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
int mem_optimazation(vvi v, int ind);
void print(vvi v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (auto it : v[i])
            cout << it << " ";

        cout << endl;
    }
    cout << endl;
}
// Your task is to find min path sum from any cell of top to any other cell of last row
// recursive code TC O(m* 3^(n*m))
int recur(vvi v, int i, int j, int n)
{
    if (i == n - 1 and j >= 0 and j < v[0].size())
        return v[i][j];
    if (j < 0 or j >= v[0].size())
        return -1;
    else
    {
        int b = recur(v, i + 1, j, n);
        int bl = recur(v, i + 1, j - 1, n);
        int br = recur(v, i + 1, j + 1, n);
        return v[i][j] + max(b, max(bl, br));
    }
}

int memo(vvi v, int i, int j, int n, vvi &dp)
{
    if (i == n - 1 and j >= 0 and j < v[0].size())
    {
        return v[i][j];
    }
    if (j < 0 or j >= v[0].size())
        return -1;
    if (dp[i][j] != -1)
        return dp[i][j];

    int b = memo(v, i + 1, j, n, dp);
    int bl = memo(v, i + 1, j - 1, n, dp);
    int br = memo(v, i + 1, j + 1, n, dp);
    return dp[i][j] = v[i][j] + max(b, max(bl, br));
}

void ans(vvi v)
{
    int mx = -1;
    for (int i = 0; i < v[0].size(); i++)
    {
        vvi dp(v.size(), vi(v[0].size(), -1));
        mx = max(mx, memo(v, 0, i, v.size(), dp));
        // print(dp);
    }
    cout << "Ans using memo : " << mx << endl;
}
// tabultion TC O(nxm) and SC : O(nxm)

void ans3(vvi v)
{
    int n = v.size();
    int m = v[0].size();
    vvi dp(v.size(), vi(v[0].size(), -1));
    int mx = -1;
    for (int k = 0; k < m; k++)
    {
        dp[0][k] = v[0][k];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int u = dp[i - 1][j];
                int ul = (j > 0) ? dp[i - 1][j - 1] : -1;
                int ur = (j < m - 1) ? dp[i - 1][j + 1] : -1;
                int x = max(u, max(ul, ur));
                dp[i][j] = (x != -1) ? v[i][j] + x : -1;
                if (i == n - 1)
                    mx = max(mx, dp[i][j]);
            }
        }
    }
    cout << "Ans using memo : " << mx << endl;
}

// space optimization
void pnt(vi v)
{

    for (auto it : v)
        cout << it << " ";

    cout << endl;
}
void ans4(vvi v)
{

    int n = v.size();
    int m = v[0].size();
    print(v);
    int mx = -1;
    for (int k = 0; k < m; k++)
    {
        vector<int> p(m, -1), q(m, -1);
        p[k] = v[0][k];
        for (int i = 1; i < n; i++)
        {
            pnt(p);
            for (int j = 0; j < m; j++)
            {
                int u = p[j];
                int ul = (j > 0) ? p[j - 1] : -1;
                int ur = (j < m - 1) ? p[j + 1] : -1;
                int x = max(u, max(ul, ur));
                q[j] = (x != -1) ? v[i][j] + x : -1;
                if (i == n - 1)
                    mx = max(mx, q[j]);
            }
            p = q;
        }
    }
    cout << "Ans using memo : " << mx << endl;
}

int main()
{
    vvi v = {{1, 2, 1, 4},
             {1, 3, 2, 1},
             {1, 1, 5, 2},
             {1, 2, 2, 1}};
    ans4(v);
    ans3(v);
    return 0;
}
