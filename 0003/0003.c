/**
 * raw version:
 * ----Runtime: 0 ms
 * --------beats 100 % of c submissions.
 * ----Memory Usage: 7.1 MB
 * --------beats 100 % of c submissions.
 */
int lengthOfLongestSubstring(char * s){
    int max = 0, start = 0, index;
    int tbl[128];
    for(index = 0; index < 128; index++) {
        tbl[index] = -1;
    }
    
    index = 0;
    
    while(s[index] != '\0') {
        if(tbl[s[index]] != -1 && tbl[s[index]] + 1 > start) {
            start = tbl[s[index]] + 1;
        }
        tbl[s[index]] = index;
        
        if(max < index - start + 1) {
            max = index - start + 1;
        }
        index++;
    }
    
    return max;
}
