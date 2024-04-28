#include <bits/stdc++.h>
using namespace std;
void print(vector<int>v){
    for(auto it:v)cout<<it<<" ";

    cout<<endl;
}
/*
U are given n and x .. create  a arr of length n
where every element are in increasing order and
AND of all ele = x
min return v[n-1]

*/
// approach : as we need and of x so min num must be x
void bit_set(int &x, int bit)
{
    x = (x | (1 << bit));
}
void minEnd(int n, int x)
{
    vector<int> unsetBit;
    for (int i = 0; i <= 32; i++)
    {
        if ((x & (1 << i)) == 0)
        {
            unsetBit.push_back(i);
        }
    }
    int req = n - 1;
    int i = 0;
    print(unsetBit);
    while (req != 0)
    {
        if ((req & 1) == 1)
        {
            bit_set(x, unsetBit[i]);
        }
        i++;
        req=req>>1;
    }
    cout << "The endMin number will be " << x;
}

int main()
{
    int n=398,x=98762;
    minEnd(n,x);

    return 0;
}