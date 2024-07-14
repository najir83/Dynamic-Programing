#include <bits/stdc++.h>
using namespace std;
using vc = vector<int>;
int dp[2001][4001];
void findSubsetSums(std::vector<int> &arr, int &mx, int index, int currentSum)
{
    if (index == arr.size())
    {

        return;
    }
    if (currentSum < arr[index])
    {
        mx = max(mx, currentSum + arr[index]);
        findSubsetSums(arr, mx, index + 1, currentSum + arr[index]);
    }

    findSubsetSums(arr, mx, index + 1, currentSum);
}
int solve(vector<int>&r,int x,int ind){
        if(ind>=r.size()){
            return x;
        }
        if(dp[ind][x]!=-1){
            return dp[ind][x];
        }
        int npick=solve(r,x,ind+1);
        int pick=0;
        if(r[ind]>x){
            pick=solve(r,x+r[ind],ind+1);
        }
        cout<<"Max "<<max(pick,npick)<<endl;
        return dp[ind][x]=max(pick,npick);
    }

int maxTotalReward(vector<int> &v)
{
    int n = v.size();
    int mx = 0;
    sort(v.begin(), v.end());
    memset(dp,-1,sizeof(dp));
    // findSubsetSums(v, mx, 0, 0);
    return solve(v,0,0);
}
int main()
{
    vc v = {1, 6, 4, 3, 2};
    cout << maxTotalReward(v);

    return 0;
}