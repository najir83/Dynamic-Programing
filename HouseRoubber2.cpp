#include <bits/stdc++.h>
using namespace std;
/*Here the houses are placed in circle order
 where 1st will be the neighbours of last*/
using vc = vector<int>;
int maxisum_memoriOptimization(vc v,int st,int n)
{
    int p1,p2;
        p1=v[st];
        p2=0;
        
        
    for (int i = st+1; i < n; i++)
    {
        int take=v[i];
        if(i>1)take+=p2;

        int nottake=0+p1;
        p2=p1;
        p1=max(take,nottake);
    }
    cout << "The maximum sum will be : " <<p1 << endl;
    return p1;
}
int main()
{
    vc v = {1,3,1,3,100};
    int n=v.size();
    cout<<"Ans will be "<<max(maxisum_memoriOptimization(v,0,n),maxisum_memoriOptimization(v,1,n-1));

    return 0;
}