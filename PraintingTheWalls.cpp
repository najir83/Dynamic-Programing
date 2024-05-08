#include <bits/stdc++.h>
using namespace std;
using vc = vector<int>;
int PaintingCost(vc cost, vc time, int i, int n)
{
    if (n <= 0)
        return 0;
    if (i > cost.size())
        return INT_MAX;

    int pick = cost[i] + PaintingCost(cost, time, i + 1, n - 1 - time[i]);
    int notpic = PaintingCost(cost, time, i + 1, n);
    cout << " val " << min(pick, notpic) << endl;
    return min(pick, notpic);
}
// Memo Iozation
int n;
int t[501][501];

int solve(int idx, int remaining, vector<int> &cost, vector<int> &time)
{

    if (remaining <= 0)
        return 0;

    if (idx == n)
    {
        return 1e9;
    }

    if (t[idx][remaining] != -1)
    {
        return t[idx][remaining];
    }

    int paint_i = cost[idx] + solve(idx + 1, remaining - 1 - time[idx], cost, time);
    int not_paint_i = solve(idx + 1, remaining, cost, time);

    return t[idx][remaining] = min(paint_i, not_paint_i);
}

int paintWalls(vector<int> &cost, vector<int> &time)
{
    n = cost.size();

    memset(t, -1, sizeof(t));

    return solve(0, n, cost, time);
}
int main()
{
    vc cost = {1, 2, 3, 2};
    vc time = {1, 2, 3, 2};
    cout << PaintingCost(cost, time, 0, 4);
    return 0;
}