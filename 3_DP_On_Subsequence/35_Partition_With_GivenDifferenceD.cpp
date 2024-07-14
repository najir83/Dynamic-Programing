#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef float ff;
typedef vector<ll> vl;
typedef vector<vl> vll;
// Q count Partition with given difference d 
int f(int i, vi &v, int tg)
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
}

//*** Now copy past everything from "3_DP_On_Subsequence\34_Count_NumbersOfSubsetsWithSumK.exe" programm */

int main(){
vi v={4,3,1,1,2,1};
int d=2;
/*
s1-s2=d;
s2=total-s1;
2 s1=total+d
s1=(total+d)/2;


*/
int k=accumulate(v.begin(),v.end(),0);
k=((k+d)%2==0 ? ((k+d)>>1):-1);
cout<<k<<endl;
cout<<f(v.size()-1,v,k);
return 0;
}