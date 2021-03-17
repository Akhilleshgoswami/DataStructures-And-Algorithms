#include<bits/stdc++.h>
using namespace std;
std::vector<std::vector<int>> ans;
std::vector<> a;
 int totalNQueens(int n) {
        vector<string> q(n,string(n,'.'));
        nQueens(n,q,0);
        return ans;
    }
    
    void nQueens(int n, vector<string> q, int i) {
        if(i == n) {
            ans++;
            return;
        }
        
        for(int j = 0;j<n;j++) {
            if(isValid(q,i,j,n)) {
                q[i][j] = 'Q';
                nQueens(n, q, i + 1);
                q[i][j] = '.';
            }
        }
    }
    
    bool isValid(vector<string> q, int row, int col, int n) {
        for(int i = 0;i<row;i++) {
            if(q[i][col] == 'Q')return false;
        }
        for(int i = row - 1, j = col - 1; i>=0 && j >= 0; i--, j--) {
            if(q[i][j] == 'Q')return false;
        }
        for(int i = row -1, j = col +1;i>=0 && j<n;i--,j++) {
            if(q[i][j] == 'Q')return false;
        }
        return true;
    }
int main(int argc, char const *argv[])
{

return 0;	

}