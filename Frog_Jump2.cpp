#include <bits/stdc++.h>
using namespace std;
void print(vector<int>v){
    for(auto it:v)cout<<it<<" ";

    cout<<endl;
}
/* u are allowing to jump up to kth index */
// using recursion
int jumping(vector<int> v, int n, int k)
{
    if (n == 0)
        return 0;

    int minjump = INT_MAX, jump = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n >= i)
        {
            jump = jumping(v, n - i, k) + abs(v[n] - v[n - i]);
            minjump = min(minjump, jump);
        }
        else
            break;
    }
    cout << "Call end for " << n << endl;

    return minjump;
}
// memoiozation technique
int jumping2(vector<int> v, vector<int> &dp, int n, int k)
{
    if (n == 0 || dp[n] != -1)
    {
        // cout<<"Return value for "<<n<<endl;
        return dp[n];
    }

    int minjump = INT_MAX, jump = INT_MAX;
    for (int i = k; i > 0; i--)
    {
        if (n >= i)
        {
            jump = jumping2(v, dp, n - i, k) + abs(v[n] - v[n - i]);
            minjump = min(minjump, jump);
        }
    }
    cout << "Call end for " << n << endl;
    dp[n] = minjump;
    return dp[n];
}
void jumping3(vector<int> v, int k) // TC +O(n) and SC : O(2n)
{
    int n = v.size();
    vector<int> dp(n, -1);
    dp[0]=0;
    dp[1] = abs(v[0] - v[1]);

    for (int j = 2; j < n; j++)
    {
        int minjump = INT_MAX, jump = INT_MAX;
        if (dp[j] != -1)
        {
            minjump = dp[j];
        }
        else
        {
            for (int i = k; i > 0; i--)
            {
                if (j>= i)
                {
                    jump = dp[j-i]+ abs(v[j] - v[j - i]);
                    minjump = min(minjump, jump);
                }
            }
            dp[j]=minjump;
        }
    }
    print(dp);
    cout << "The will be " << dp[n - 1];
}
int main()
{
    vector<int> v = {10, 40, 50, 20, 60};
    int k = 3;
    vector<int> dp(5, -1);
    dp[0] = 0;
    cout << jumping(v, 4, k) << endl;
    cout << jumping2(v, dp, 4, k) << endl;
    print(dp);
    jumping3(v,k);

    return 0;
}