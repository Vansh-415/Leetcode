class Solution {
public:
    bool isSubstring(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        if(m > n) return false;
        
        long long p = 31, MOD = 1e9+7;
        long long patternHash = 0, textHash = 0, pPow = 1;
        
        for(int i = 0; i < m; i++) {
            patternHash = (patternHash * p + pattern[i]) % MOD;
            textHash = (textHash * p + text[i]) % MOD;
            if(i < m-1) pPow = (pPow * p) % MOD;
        }
        
        for(int i = 0; i <= n - m; i++) {
            if(textHash == patternHash && text.substr(i, m) == pattern) {
                return true;
            }
            if(i < n - m) {
                textHash = ((textHash - text[i]*pPow % MOD + MOD) % MOD * p + text[i+m]) % MOD;
            }
        }
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;
        
        while(repeated.size() < b.size()) {
            repeated += a;
            count++;
        }
        
        if(isSubstring(repeated, b)) return count;
        
        repeated += a;
        count++;
        if(isSubstring(repeated, b)) return count;
        
        return -1;
    }
};