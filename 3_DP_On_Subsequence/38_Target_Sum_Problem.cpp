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
// Target sum by assign signs
int No_Of_Target_Ways(vi &v, int i, int tg, int s)
{
    // base case
    if (i == 0)
    {
        return ((s + v[0] == tg or s - v[i] == tg) ? 1 : 0);
    }

    // body
    int x = No_Of_Target_Ways(v, i - 1, tg, s - v[i]);
    int y = No_Of_Target_Ways(v, i - 1, tg, s + v[i]);
    return x + y;
}

int Memo(int i, vi &v, int tg, int s, vector<unordered_map<int,int>>&dp)
{
    if (i == 0)
    {  //cout<<s<<endl;
        return ((s + v[0] == tg or s - v[i] == tg) ? 1 : 0);
    }
    if (dp[i].find(s)!=dp[i].end())
        return dp[i][s];

    // body
    int x = Memo(i - 1, v, tg, s - v[i], dp);
    int y = Memo(i - 1, v, tg, s + v[i], dp);
    //cout<<i<<" "<<tg<<" "<<x+y<<endl;
    return dp[i][s] = x + y;
}
/*int f(int i, vi &v, int tg)
{

    if (tg == 0)
        return 1;
    if (i == 0)
        return v[0] == tg;

    int pick, notPick;
    pick = notPick = 0;
    pick = (v[i] <= tg ? f(i - 1, v, tg - v[i]) : 0);
    notPick = f(i - 1, v, tg);
    return pick + notPick;
}*/
int main()
{
    vi v = {1, 2, 3, 1};
    int n = v.size();
    int d = 3;
    //   cout << No_Of_Target_Ways(v, n - 1, 3, 0); //using recursion
    // with the help of partition sum with given difference ** just copy past it
    /* int k = accumulate(v.begin(), v.end(), 0);
     k = ((k + d) % 2 == 0 ? ((k + d) >> 1) : -1);
     // cout<<k<<endl;
     cout << f(v.size() - 1, v, k);*/

    vector<unordered_map<int,int>> dp(n);
   

    cout<<Memo(n - 1, v, d, 0, dp);
    // pnt(dp);
    return 0;
}