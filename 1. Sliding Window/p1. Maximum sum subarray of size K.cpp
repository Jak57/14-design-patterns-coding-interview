// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

long maximumSumSubarray(int K, vector<int> &Arr , int N){ 
    long sum = 0, mx;
    int i, j;
    for (i = 0; i < K; i++)
    {
        sum += long(Arr[i]);
    }
    mx = sum;
    for (i = K; i < N; i++) {
        sum = sum + long(Arr[i]) - long(Arr[i-K]);
        mx = max(sum, mx);
    }
    return mx;
}
