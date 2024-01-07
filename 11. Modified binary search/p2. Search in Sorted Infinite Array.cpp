// https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
// https://www.youtube.com/watch?v=awMDD7sGWVU&ab_channel=AnujBhaiya
// Bismillah
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve()
{
    int n, i, j, target = 10;
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};

    int l = 0, r = 1, m;
    while (arr[r] < target) {
        l = r;
        r = 2*r;
    }

    while (l <= r) {
        m = l + (r - l) / 2;
        if (arr[m] == target)
            return m;
        else if (target < arr[m])
            r = m-1;
        else
            l = m+1;
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
