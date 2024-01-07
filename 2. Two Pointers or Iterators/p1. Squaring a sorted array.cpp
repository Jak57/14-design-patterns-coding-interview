// https://www.geeksforgeeks.org/sort-array-converting-elements-squares/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, arr[10000];
    vector<int> v;
    cin>> n;
    for (i = 0; i < n; i++)
        cin>> arr[i];

    int idx = -1;
    for (i = n-1; i >= 0; i--) {
        if (arr[i] < 0) {
            idx = i;
            break;
        }
    }

    int l = idx, r = idx+1;
    vector<int> ans;
    while (l >= 0 && r < n) {
        int num1 = arr[l] * arr[l];
        int num2 = arr[r] * arr[r];
        if (num1 <= num2) {
            ans.push_back(num1);
            l--;
        } else {
            ans.push_back(num2);
            r++;
        }
    }
    while (l >= 0)
    {
        ans.push_back(arr[l]*arr[l]);
        l--;
    }

    while (r < n) {
        ans.push_back(arr[r]*arr[r]);
        r++;
    }

    for (i = 0; i < ans.size(); i++)
        cout<< ans[i] << " ";
    cout<< "\n";

    return 0;
}

/*
6
-6 -3 -1 2 4 5
*/

