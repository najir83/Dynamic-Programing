#include <bits/stdc++.h>
using namespace std;
// Func Tools
template <class Fun>
class najir_result
{
    Fun fun_;

public:
    template <class T>
    explicit najir_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) najir(Fun &&fun) { return najir_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef float ff;
typedef vector<ll> vl;
typedef vector<vl> vll;
// memoiozation
int cutRod(int v[], int n)
{
    int mx = 0;
    vii dp(n, vi(n + 1, -1));
    auto f = najir([&](const auto &f, int i, int *v, int len) -> int
                   {
                       if (i == 0)
                       {
                        return (len>0 ? len*v[0]:0);
                       }
                       if(dp[i][len]!=-1)return dp[i][len];

                       int take = 0, nt = 0;
                       if (len >= i + 1)
                       {
                           take = v[i] + f(i, v, len-i-1);
                       }
                       nt = f(i - 1, v, len);
                       return dp[i][len]=max(take, nt); });

    mx = f(n - 1, v, n);
    return mx;
}

// tabulation
int tabu(int v[], int n)
{
    int mx = 0;
    vii dp(n, vi(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = i * v[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int take = 0, nt = 0;
            if (j >= i + 1)
            {
                take = v[i] + dp[i][j - i - 1];
            }
            nt = dp[i - 1][j];
            dp[i][j] = max(take, nt);
        }
    }
    return dp[n - 1][n];
    // TC : O(n*n)
    // SC : O(n*n)
}

// space optimization 2 one d array

int space_optimization(int v[], int n)
{
    int mx = 0;
    // vii dp(n, vi(n + 1, 0));
    vi p(n + 1, 0), q(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i * v[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int take = 0, nt = 0;
            if (j >= i + 1)
            {
                take = v[i] + q[j - i - 1];
            }
            nt = p[j];
            q[j] = max(take, nt);
        }
        p = q;
    }
    return p[n];
}

// space optimization 1 one d array

int space_optimization(int v[], int n)
{
    int mx = 0;
    // vii dp(n, vi(n + 1, 0));
    vi p(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i * v[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int take = 0, nt = 0;
            nt = p[j];
            if (j >= i + 1)
            {
                take = v[i] + p[j - i - 1];
            }
            p[j] = max(take, nt);
        }
        // p = q;
    }
    return p[n];
}

int main()
{

    return 0;
}