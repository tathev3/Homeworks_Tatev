int sockMerchant(int n, vector<int> ar) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (ar[i] == -1) {
            continue;
        }

        int currentSockColor = ar[i];
        int matchingSocks = 1; 
        ar[i] = -1;

        for (int j = i + 1; j < n; j++) {
            if (ar[j] == currentSockColor) {
                matchingSocks++;
                ar[j] = -1;
            }
        }
        count += matchingSocks / 2; 
    }

    return count;
}