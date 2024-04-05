string isValid(string s) {
    unordered_map<char, int> frequency;
    for (char c : s) {
        frequency[c]++;
    }
    unordered_map<int, int> freqOfFreq;
    for (auto& pair : frequency) {
        freqOfFreq[pair.second]++;
    }
    if (freqOfFreq.size() == 1) return "YES";

    if (freqOfFreq.size() == 2) {
        auto it = freqOfFreq.begin();
        int freq1 = it->first, count1 = it->second;
        ++it;
        int freq2 = it->first, count2 = it->second;
        if ((count1 == 1 && (freq1 - 1 == freq2 || freq1 == 1)) ||
            (count2 == 1 && (freq2 - 1 == freq1 || freq2 == 1))) {
            return "YES";
        }
 
    return "NO";
}