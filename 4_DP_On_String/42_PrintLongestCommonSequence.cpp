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
int dp[1005][1005];
void tabu(string &a, string &b)
{
    int n = a.size();
    int m = b.size();
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = 1 + dp[i][j];
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
void Match_Sequence(string a, string b)
{
    tabu(a, b);
    int n = a.size(), m = b.size();
    string ans = "";
    int i = n, j = m;
    while (i != 0 and j != 0)
    {
        if (a[i - 1] == b[j - 1])
            ans.push_back(a[i-1]), i = i - 1, j = j - 1;
        else
        {
            if (dp[i][j] == dp[i - 1][j])
                i = i - 1;
            else
                j = j - 1;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main()
{
    string a =  "abaaa" ;
    string b = "abcde";
    Match_Sequence(a, b);

    return 0;
}