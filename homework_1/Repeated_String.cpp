long repeatedString(string s, long n) {
    int a_count = 0;
    for (char ch : s) {
        if (ch == 'a') {
            a_count++;
        }
    }
    
    size_t repeat = n / s.size();
    size_t tmp = n % s.size();
    int tmp_count = 0;
    
    for (size_t i = 0; i < tmp; i++) {
        if (s[i] == 'a') {
            tmp_count++;
        }
    }
    
    long count = repeat * static_cast<long>(a_count) + tmp_count;

    return count;
}