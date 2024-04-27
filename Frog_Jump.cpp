/*  You are given a 0-indexed integer array stones
representing the positions of stones in a river.

A frog, initially on the first stone, wants to travel
 to the last stone and then return to the first stone.
  However, it can jump to any stone at most once.

The length of a jump is the absolute difference between
the position of the stone the frog is currently on and
 the position of the stone to which the frog jumps.*/
#include <bits/stdc++.h>
using namespace std;
// using recurion
/*int gap(vector<int> v, int n)
{
    if (n == 0)
        return 0;

    int right = INT_MAX, left = INT_MAX;
    left = gap(v, n - 1) + abs(v[n] - v[n - 1]);
    if (n > 1)
    {
        right = gap(v, n - 2) + abs(v[n] - v[n - 2]);
    }
    return min(right, left);
}
// Memoiozation technique
int gap2(vector<int> v,vector<int>&dp, int n)
{
    if (n == 0 ||dp[n]!=-1)
        return dp[n];

    int right = INT_MAX, left = INT_MAX;
    left = gap(v, n - 1) + abs(v[n] - v[n - 1]);
    if (n > 1)
    {
        right = gap(v, n - 2) + abs(v[n] - v[n - 2]);
    }
    return dp[n]=min(right, left);
}
void minCost(vector<int> v) //TC +O(n) and SC : O(2n)
{
    int n = v.size();
    vector<int> dp(n, -1);
    dp[0]=0;
    cout << gap2(v, dp, n - 1);
}*/
//trabulation
void minCost(vector<int> v) //TC +O(n) and SC : O(2n)
{
    int n = v.size();
    vector<int> dp(n, -1);
    dp[0]=0;
    dp[1]=abs(v[0]-v[1]);
    for(int i=2;i<n;i++){
       dp[i]=min(dp[i-1]+abs(v[i] - v[i - 1]),dp[i-2]+abs(v[i] - v[i - 2]));
        
    }
    cout<<dp[n-1];
}
//Manage memory
void minCost2(vector<int> v) //TC +O(n) and SC : O(2n)
{
    int n = v.size();
    int p1,p2;
    p1=0;p2=abs(v[0]-v[1]);
    
    for(int i=2;i<n;i++){
       int tem=min(p2+abs(v[i] - v[i - 1]),p1+abs(v[i] - v[i - 2]));
        p1=p2;

        p2=tem;


    }
    cout<<p2;
}

int main()
{
    vector<int> v = {30, 10, 60, 10, 60, 50};
    // cout << gap(v, 5);
    minCost(v);

    return 0;
}