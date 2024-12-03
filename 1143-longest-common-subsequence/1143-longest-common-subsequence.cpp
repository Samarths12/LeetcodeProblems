class Solution {
public:

    int solveusingRec(string a, string b, int i, int j) {
        //base case
        if(i >= a.length() || j >= b.length()) return 0;

        //rec call
        int ans = 0;

        if(a[i] == b[j]) {
            ans = 1 + solveusingRec(a, b, i+1, j+1);
        }
        else{
            ans = 0 + max(solveusingRec(a, b, i+1, j),
                       solveusingRec(a, b, i, j+1));
        }

        return ans;
    }


    int solveusingMem(string& a, string& b, int i, int j, vector<vector<int> >& dp ) {

        if(i >= a.length() || j >= b.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        //rec call
        int ans = 0;

        if(a[i] == b[j]) {
            ans = 1 + solveusingMem(a, b, i+1, j+1, dp);
        }
        else{
            ans = 0 + max(solveusingMem(a, b, i+1, j, dp),
                       solveusingMem(a, b, i, j+1, dp));
        }

        dp[i][j] = ans;
        return dp[i][j];

    }


    int solveusingTab(string a, string b) {
        //base case ko analyse krke yahi pr 0 krdiya
       vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i_index = a.length()-1 ; i_index >=0; i_index--) {
            for(int j_index = b.length()-1; j_index >= 0; j_index--) {

                int ans = 0;

             if(a[i_index] == b[j_index]) {
            ans = 1 + dp[i_index+1][j_index+1];
            }
             else{
            ans = 0 + max(dp[i_index+1][j_index], dp[i_index][j_index+1]);
        }

        dp[i_index][j_index] = ans;

        

            }
        }
        return dp[0][0];
    }


    int solveusingSpaceOpt(string a, string b) {

        // vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, -0));
        vector<int> next(a.length()+1, 0);
        vector<int> curr(a.length()+1, 0);


        
            for(int j_index = b.length()-1; j_index >= 0; j_index--) {
                for(int i_index = a.length()-1 ; i_index >=0; i_index--) {

                int ans = 0;

             if(a[i_index] == b[j_index]) {
            ans = 1 + next[i_index+1];
            }
             else{
            ans = 0 + max(curr[i_index+1], next[i_index]);
        }

        curr[i_index] = ans;
            }
            next = curr;
        }
        return next[0];
    }



    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // return solveusingRec(text1, text2, i, j);

        // vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1, -1));

        // return solveusingMem(text1, text2, i, j, dp);

        // return solveusingTab(text1, text2);

        return solveusingSpaceOpt(text1, text2);
        
    }
};