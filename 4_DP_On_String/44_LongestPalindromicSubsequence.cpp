#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef float ff;
typedef vector<ll> vl;
typedef vector<vl> vll;
// Func Tools

void pnt(vi &v)
{

    for (auto it : v)
        cout << it << " ";

    cout << endl;
}
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

int longest_Palindromic_Subsequence(string &a)
{

    int n = a.size();
    string b = a;
    reverse(b.begin(), b.end());
    // cout<<a<<" "<<b<<endl;
    int dp[1005][1005];

    // memoiozation
    /*
    memset(dp, -1, sizeof(dp));
        auto f = najir([&](const auto &f, int i, int j) -> int
                       {
                           if (i < 0 or j < 0)
                               return 0;
                            if(dp[i][j]!=-1)return dp[i][j];
                           int tk = 0;
                           if (a[i] == b[j])
                           {
                               tk = 1 + f(i - 1, j - 1);
                           }
                           tk = max(tk, max(f(i - 1, j), f(i, j - 1)));
                           return dp[i][j]=tk;
                       });
                    cout<<f(a.size()-1,a.size()-1);

                    return 0;*/

    // Tabulation
    /*
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i < i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = 1 + dp[i][j];
            }
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(dp[i][j + 1], dp[i + 1][j]));
        }
    }
    cout << dp[n][n] << endl;
    */
    // space optimization
    vi pre(n + 1), cur(n + 1);
    for (int i = 0; i < n; i < i++)
    {
        for (int j = 0; j < n; j++)
        {
          
            if (a[i] == b[j])
            {
                cur[j+1] = 1 + pre[j];
            }
            cur[j + 1] = max(cur[j+1], max(pre[j + 1], cur[j]));
        }
        pre=cur;
    }
    pnt(cur);

    return 0;
}

int main()
{
    string s = "bbabcbcab";
    longest_Palindromic_Subsequence(s);

    return 0;
}