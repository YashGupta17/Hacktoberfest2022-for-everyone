class Solution {
   
    
public:
    bool isMatch(string s, string p) {
        int l1  = p.length()  , l2 = s.length();
        vector<vector<bool>> dp(l1+1 , vector<bool> (l2+1  )) ;
        dp[0][0] = true ; 
        for(int i = 1 ; i<= l1 ; ++i){
            if(p[i -1 ] ==  '*')dp[i][0] = true&&dp[i-1][0] ; 
            else dp[i][0] = false ; 
        }
        for(int i  = 1 ; i<=l2 ; ++i ){
            dp[0][i] = false ; 
        }
        for(int i = 1 ; i<= l1 ; ++i ) {
            for(int j = 1 ; j<= l2 ; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?')dp[i][j] = dp[i-1][j-1] ; 
                else if(p[i-1] == '*'){
                   
                    dp[i][j] = dp[i-1][j-1] ||  dp[i-1][j] || dp[i][j-1] ;
                }
                else {
                    dp[i][j] = false ;
                }
               
            }
        }
        
        return dp[l1][l2] ;
    }
};
