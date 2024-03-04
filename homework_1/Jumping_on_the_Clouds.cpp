int jumpingOnClouds(vector<int> c) {
    int n = c.size();
    int jumps = 0;
    
    for (int i = 0; i < n - 1; ) {  
        if (i + 2 < n && c[i + 2] == 0) {
            i += 2;
        } else {
            i += 1;
        }
        jumps++; 
    }
    
    return jumps;

}
