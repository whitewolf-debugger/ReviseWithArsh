class Solution {
public:
    string longestPrefix(string s) {
        //rolling hash method 
        long long n = s.size();
        long long pow = 1;
        long long base = 26;
        long long ph = 0;
        long long sh = 0;
        long long ans = 0;
        long long MOD = 1e9 + 7;
        for(int i =0; i < n-1; i++) {
            ph = (ph *base + (s[i] - 'a' + 1))%MOD ;
            sh = (sh+ (s[n-i- 1] - 'a'+ 1)*pow)% MOD;
            pow = pow * base % MOD;
            if(ph == sh) {
                ans = i + 1;
            }
        }
        
        return s.substr(0, ans);
    }
};
/*
base = p    
prefix hash     (ph *base + (s[i] - 'a' + 1)) 
                a   b   a   b   a   b
suffix hash    sh = (sh+ (s[n-i- 1] - 'a'+ 1)*pow)% MOD;                


*/
