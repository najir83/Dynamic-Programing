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
void pnt(vii &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (auto it : dp[i])
            cout << it << " ";

        cout << endl;
    }
    cout << endl;
}
void tabu(string &a, string &b)
{
    int n = a.size(), m = b.size();
    vii dp(n + 1, vi(m + 1));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    pnt(dp);

    cout << ans << endl;
}
void space_omit(string &a, string &b)
{
    int n = a.size(), m = b.size();
    vi pre(m + 1), cur(m + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                cur[j] = 1 + pre[j - 1];
                ans = max(ans, cur[j]);
            }
            else
            {
                cur[j] = 0;
            }

        }
        pre=cur;
    }
  

    cout << ans << endl;
}

int main()
{
    string a = "abcjklp", b = "acjkp";
    //tabu(a, b);
space_omit(a,b);
    return 0;
}