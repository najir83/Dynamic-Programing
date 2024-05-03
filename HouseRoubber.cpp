#include <bits/stdc++.h>
using namespace std;
using vc = vector<int>;
/*Given a arr
return maximum subsequence sum
non of two ele are adjacent
*/

/*MY CODE
void recsum(vc v, int i, int sum, int &mxsum)
{
    if (i >= v.size())
    { cout<<sum<<" ";
        mxsum = max(mxsum, sum);
        return;
    }
    recsum(v, i + 2, sum + v[i], mxsum);
    recsum(v, i + 1, sum, mxsum);
}
void maxisum(vc v)
{
    int n = v.size();
    int mxsum = INT_MIN;
    recsum(v,0,0,mxsum);
    cout<<"The maximum sum will be : "<<mxsum<<endl;
}
*/
int recsum(vc v, int n)
{
    if (n == 0)
        return v[0];
    if (n < 0)
        return 0;

    int pic, notpic;
    pic = v[n] + recsum(v, n - 2);
    notpic = recsum(v, n - 1);
    return max(pic, notpic);
}
void maxisum(vc v)
{
    int n = v.size();

    int mxsum = recsum(v, n - 1);
    cout << "The maximum sum will be : " << mxsum << endl;
}
// TC=2^n
// Let's add memo iozation technique
int recsum(vc v, vc &dp, int n)
{
    if (n == 0)
        return v[0];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int pic, notpic;
    pic = v[n] + recsum(v, dp, n - 2);
    notpic = recsum(v, dp, n - 1);
    dp[n] = max(pic, notpic);
    return max(pic, notpic);
}
void maxisum2(vc v)
{
    int n = v.size();
    vc dp(n, -1);
    dp[0] = v[0];
    int mxsum = recsum(v, dp, n - 1);
    cout << "The maximum sum will be : " << mxsum << endl;
}
// TC=O(n)
//SC=O(2n)
// trabulation technique
void maxisum_trabulation(vc v)
{
    int n = v.size();
    vc dp(n, -1);
    dp[0] = v[0];
    dp[1] = v[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(v[i] + dp[i - 2], dp[i - 1]);
    }
    cout << "The maximum sum will be : " <<dp[n-1] << endl;
    // TC=O(n)
//SC=O(2n)
}
//memori optimization
int maxisum_memoriOptimization(vc v)
{
int n = v.size();
    int p1,p2;
        p1=v[0];
        
        if(n==1)return p1;
        p2=v[1];
        p2=max(p1,p2);
        if(n==2)return p2;
        
    for (int i = 2; i < n; i++)
    {
        int tem=p2;
        p2=max((v[i]+p1),p2);
        p1=tem;
    }
    cout << "The maximum sum will be : " <<p2 << endl;
    return p2;
}
int main()
{
    vc v = {2, 7, 9, 3, 1};
    // maxisum(v);
    maxisum2(v);
maxisum_trabulation(v);
maxisum_memoriOptimization(v);
    return 0;
}