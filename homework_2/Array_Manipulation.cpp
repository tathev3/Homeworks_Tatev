long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);

    for (const auto& q : queries) {
        int a = q[0], b = q[1], k = q[2];
        arr[a] += k; 
        if (b + 1 <= n) arr[b + 1] -= k;
    }

    long maxx = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += arr[i];
        maxx = max(maxx, sum);
    }
    return maxx;
}