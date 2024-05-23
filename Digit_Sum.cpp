int superDigit(string n, int k) {
    
    if (n.length() == 1 && k == 1) 
        return n[0] - '0';
    
    long sum = 0;
    for (char digit : n) 
        sum += digit - '0';
    
    sum = sum*k;
    std::string new_n = std::to_string(sum);
    
    return superDigit(new_n, 1);
    
}