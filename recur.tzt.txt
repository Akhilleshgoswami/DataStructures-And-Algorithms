   
1)Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.







 void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
        if(ind == arr.size()) {
            if(target == 0) {
                ans.push_back(ds); 
            }
            return; 
        }
        // pick up the element 
        if(arr[ind] <= target) {
            ds.push_back(arr[ind]); 
            findCombination(ind, target - arr[ind], arr, ans, ds); 
            ds.pop_back(); 
        }
        
        findCombination(ind+1, target, arr, ans, ds); 
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        findCombination(0, target, candidates, ans, ds); 
        return ans; 
    }



combination 2 problem
 vector<vector<int>> ans;
//STORE THE FINAL RESULT

void solve(int cI, int sum, const vector<int>& candidates, vector<int>& vec){
    if(sum < 0){return;} 
    if(cI == candidates.size()){
        if(sum == 0){
            ans.push_back(vec);
        }
        return;
    }
    if(sum == 0){
        ans.push_back(vec);
        return;
    }
    for(int i = cI; i < candidates.size(); i++){
        if(i > cI && candidates[i] == candidates[i-1]){continue;}
        vec.push_back(candidates[i]);
        solve(i+1, sum - candidates[i], candidates, vec);
        vec.pop_back();
    }
    
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    ans.reserve(100);

	vector<int> cd = candidates;		
    sort(cd.begin(), cd.end());
          
    vector<int> vec; vec.reserve(100);
    
	solve(0, target, cd, vec);
	
    return ans;
}
combinantino 3
 vector<vector<int>> result;
    void try_combination(vector<int>& combination, int k, int n, int start){
        if(k == combination.size()){
            if(n == 0) result.push_back(combination);
            return;
        }
        for(int i = start; i <= 9; ++i){
            combination.push_back(i);
            try_combination(combination, k, n-i, i+1);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        try_combination(combination, k, n, 1);
        return result;
    }

n queen 1
class Solution {
public:
    
    vector<string>a;
    vector<vector<string>>ans;
    bool isValid(int n , int row , int col){
        int total=0;
        // row wise check
        for(int i=0;i<n;i++){
            if(a[row][i]=='Q')
                total++;
        }
        if(total>0)
            return false;
        //column wise check
        total=0;
        for(int i=0;i<n;i++){
            if(a[i][col]=='Q')
                total++;
        }
        if(total>0)
            return false;
        // top left to bottom right diagonal
        total=0;
        for(int i=0;i<n;i++){
            if(row+i<n && col+i<n){
                if(a[row+i][col+i]=='Q')
                    total++;
            }
            else
                break;
        }
        if(total>0)
            return false;
        total=0;
        for(int i=0;i<n;i++){
            if(row-i>=0 && col-i>=0){
                if(a[row-i][col-i]=='Q')
                    total++;
            }
            else
                break;
        }
        if(total>0)
            return false;
        // from top right to bottom left
         total=0;
        for(int i=0;i<n;i++){
            if(row+i<n && col-i>=0){
                if(a[row+i][col-i]=='Q')
                    total++;
            }
            else
                break;
        }
        if(total>0)
            return false;
         total=0;
        for(int i=0;i<n;i++){
            if(row-i>=0 && col+i<n){
                if(a[row-i][col+i]=='Q')
                    total++;
            }
            else
                break;
        }
        if(total>0)
            return false;
        return true;
    }

    void ok(int n , int rowNo){
        if(rowNo==n){
            ans.push_back(a);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(n,rowNo,i)){
                a[rowNo][i]='Q';
                ok(n,rowNo+1);
                a[rowNo][i]='.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        string start="";
        for(int i=0;i<n;i++)
            start=start+(".");
        a=vector<string>(n,start);
        ok(n,0);
        return ans;
    }
};






N queen sproblem 2
class Solution {
public:
    int ans = 0;
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
