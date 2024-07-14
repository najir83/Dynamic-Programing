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
// recursion
/*bool subset_sum(vi &v, int i, int s)
{
    if (s == 0)
        return true;
    if (i == 0)
        return s == v[0];

    bool t, nt;
    t = nt = false;
    if (v[i] <= s)
    {
        t = subset_sum(v, i - 1, s - v[i]);
    }
    nt = subset_sum(v, i - 1, s);

    return (t or nt);
}

// Tabulation
vii dp;
bool subset_sum2(vi &v, int i, int s)
{
    if (s == 0)
        return true;
    if (i == 0)
        return s == v[0];

    if (dp[i][s] != -1)
    {
        // cout << "calls for " << i << endl;
        return dp[i][s];
    }

    bool t, nt;
    t = nt = false;
    if (v[i] <= s)
    {
        t = subset_sum2(v, i - 1, s - v[i]);
    }
    nt = subset_sum2(v, i - 1, s);

    return dp[i][s] = (t or nt);
}
*/

void Partion_Subset_Sum(vi &v, int n)
{
    int sm = accumulate(v.begin(), v.end(), 0);
    sm = ((sm % 2 == 0) ? sm / 2 : -1);
    if (sm == -1)
        return;
    // cout<<subset_sum(v,n-1,sm)<<endl;
    // dp.resize(n + 1, vector<int>(sm + 1, -1));

    // cout << subset_sum2(v, n - 1, sm) << endl;
    // pnt(dp);
}
void Tabulation_Solution(vi v, int n)
{
    int sm = accumulate(v.begin(), v.end(), 0);
    sm = ((sm % 2 == 0) ? sm / 2 : -1);
    if (sm == -1)
        return;
    vii dp(n, vector<int>(sm + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    dp[0][v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= sm; s++)
        {
            dp[i][s] = (dp[i - 1][s] or ((v[i] <= s) ? dp[i - 1][s - v[i]] : 0));
        }
    }
    pnt(dp);
    cout << "Result : " << dp[n - 1][sm] << endl;
}

void Space_Optimization(vi v,int n){
    int sm = accumulate(v.begin(), v.end(), 0);
    sm = ((sm % 2 == 0) ? sm / 2 : -1);
    if (sm == -1)
        return;

    vector<bool>p(sm+1,false),q(sm+1,false);
    p[v[0]]=1;
    p[0]=1;
    for (int i = 1; i < n; i++)
    {
        for (int s = 1; s <= sm; s++)
        {
            q[s] = (p[s] or ((v[i] <= s) ? p[s - v[i]] : 0));
        }
        p=q;
        for(int i=0;i<=sm;i++)q[i]=0;

        q[0]=1;
    }
    
cout << "Result : " << p[sm] << endl;
}

int main()
{
    vi v = {2, 3, 3, 3, 4, 5};
    int n = v.size();
    // Partion_Subset_Sum(v, n);
    //Tabulation_Solution(v,n);
    Space_Optimization(v,n);
    return 0;
}