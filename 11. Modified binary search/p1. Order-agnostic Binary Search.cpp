// https://www.geeksforgeeks.org/order-agnostic-binary-search/
// Bismillah

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve()
{
    int n, i, j, arr[1000], target;
    cin>> n >> target;
    for (i = 0; i < n; i++)
        cin>> arr[i];

    int l = 0, r = n-1, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (arr[m] == target)
            return m;
        else if (arr[l] < arr[r]) {
            if (target < arr[m])
                r = m-1;
            else
                l = m+1;
        } else {
            if (target < arr[m])
                l = m+1;
            else
                r = m-1;
        }
    }
    return -1;
}

int main()
{
    int t = 1;
    //cin>> t;
    while (t--)
        cout<< solve() << "\n";
    return 0;
}
/*
5 20
1 2 3 4 5
*/
