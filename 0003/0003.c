/**
 * raw version:
 * ----Runtime: 4 ms
 * --------beats 91.05 % of c submissions.
 * ----Memory Usage: 7.1 MB
 * --------beats 95.24 % of c submissions.
 */
int lengthOfLongestSubstring(char * s){
    int max = 0, start = 0, index = 0;
    int tbl[128];
    for(int i = 0; i < 128; i++) {
        tbl[i] = -1;
    }
    
    while(s[index] != '\0') {
        if(tbl[s[index]] != -1) {
            start = tbl[s[index]] + 1 > start ? tbl[s[index]] + 1 : start;
        }
        tbl[s[index]] = index;
        
        if(max < index - start + 1) {
            max = index - start + 1;
        }
        index++;
    }
    
    return max;
}
