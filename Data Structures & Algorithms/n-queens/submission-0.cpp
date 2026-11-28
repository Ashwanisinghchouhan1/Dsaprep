class Solution {
  unordered_map<int , bool>Row;
  unordered_map<int , bool>bleftd;
  unordered_map<int , bool>uleftd;

bool isSafe(int row , int col , vector<string>&chess , int n){

        if(Row[row] == true)
        return false;

        if(bleftd[row + col] == true)
        return false;

        if(uleftd[n - 1 + col - row] == true)
        return false;

        return true;
}

void solve(vector<string>&chess , vector<vector<string>>&ans , int n , int col){

    if(col == n){
        ans.push_back(chess);
        return ;
    }

    // now main work

    for(int row = 0; row < n; row++){
        if(isSafe(row , col , chess , n)){

            // insert Q
            chess[row][col] = 'Q';
            Row[row] = true;
            bleftd[row + col] = true;
            uleftd[n-1 +col - row] = true;

            // Recursion call
            solve(chess , ans , n , col + 1);

            // backtrack
            chess[row][col] = '.';
            Row[row] = false;
            bleftd[row + col] = false;
            uleftd[n-1 +col - row] = false;
        }

    }
}

public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> chess(n, string(n, '.'));
        int col = 0;
        vector<vector<string>>ans;
        solve(chess , ans , n, col);
        return ans;
    }
};