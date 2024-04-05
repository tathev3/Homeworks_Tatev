int makeAnagram(string a, string b) {
    int frequency[256] = {0};

    for (char c : a) {
        frequency[c]++;
    }

    for (char c : b) {
        frequency[c]--;
    }
    int deletions = 0;
    for (int i = 0; i < 256; i++) {
        deletions += abs(frequency[i]);
    }
    
    return deletions / 2;
}