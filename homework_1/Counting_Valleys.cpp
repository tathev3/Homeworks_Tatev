int countingValleys(int steps, string path) {
    int level = 0; 
    int valleys = 0; 

    for (char step : path) {
        if (step == 'U') 
            level++; 
         else if (step == 'D') 
            level--;
        
        if (step == 'U' && level == 0) 
            valleys++;
        
    }

    return valleys;
}