int minimumSwaps(vector<int> arr) {
    int n = arr.size(); 
    int swapCount = 0;  

    for (int i = 0; i < n; i++) {
        while (arr[i] != i + 1) {
            int t = arr[i];
            arr[i] = arr[arr[i] - 1];
            arr[t - 1] = t;
            swapCount++;
        }
    }
    return swapCount;
}