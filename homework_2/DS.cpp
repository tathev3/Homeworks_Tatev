int hourglassSum(vector<vector<int>> arr) {

    int maxSum = arr[0][0] + arr[0][1] + arr[0][2] +
                 arr[1][1] +
                 arr[2][0] + arr[2][1] + arr[2][2];

    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] +
                      arr[i + 1][j + 1] +
                      arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];

            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}