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
// Memoiozation
int dp[1005][1005];
int f(int i, int j, string &a, string &b)
{
    // return 0;
    if (i < 0 or j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int mx = 0;
    if (a[i] == b[j])
        mx = max(mx, 1 + f(i - 1, j - 1, a, b));

    else
    {
        mx = max(mx, f(i - 1, j, a, b));
        mx = max(mx, f(i, j - 1, a, b));
    }
    return dp[i][j] = mx;
}
// TC == O(n*m) and Space Complexity =O(n*m+n)

// Tabulation
int tabu(int n, int m, string &a, string &b)
{
    memset(dp, 0, sizeof(dp));
    // vector<int>
    for (int i = 0; i < m; i++)
    {
        if (a[0] == b[i])
            dp[0][i] = 1;
        if (i > 0)
            dp[0][i] = max(dp[0][i], dp[0][i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (b[0] == a[i])
            dp[i][0] = 1;
        if (i > 0)
            dp[i][0] = max(dp[i][0], dp[i - 1][0]);
    }

    // Fill the dp table
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n - 1][m - 1];
}
// space optimization

int spm(string a, string b)
{
    int n = a.size(), m = b.size();
    // see if we just do insted of storing value of id i and j to i and j in dp , we store it in dp[i+1][j+1] so that if i or j == -ve it will treated as false means 0 :)
    vi pre(m + 1, 0), cur(m + 1, 0);
    for (int i = 0; i < m; i++)
        pre[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                cur[j] = 1 + pre[j - 1];
            }
            else
                cur[j] = max(pre[j], cur[j - 1]);
        }
        pre=cur;
    }
    return pre[m];
}

// TC O(n*m)  SC : O(n)
int main()
{
    string a = "abcde";
    string b = "ace";
    // memo
    memset(dp, -1, sizeof(dp));
    cout << f(a.size() - 1, b.size() - 1, a, b) << endl;

    // tabu
    cout << tabu(a.size(), b.size(), a, b) << endl;

    // spm
    cout << spm(a, b) << endl;

    return 0;
}