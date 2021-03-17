#include<bits/stdc++.h>
using namespace std;
std::vector<std::vector<int>> ans;
std::vector<int> a;
bool isvalid(int n , int row , int col){
//cheaking for row
	for(int i =0;i<n;i++)
		if(a[row][i] =='Q')return false;
//cheaking for colom
	for(int i =0;i<n;i++)
		if(a[i][col] =='Q')return false;

//cheaking for top left to right bottom
for(int i =0;i<n;i++){
	if(row+i <n and col+i<n)
		 if(a[row+i][col+i] == 'Q')return false;
}
	for(int i =0;i<n;i++){
	if(row-i <n and col-i<n)
		 if(a[row-i][col-i] == 'Q')return false;
}	

// cheaking for top right to bottom left
for(int i =0;i<n;i++){
	if(row+i <n and col-i<n)
		 if(a[row+i][col-i] == 'Q')return false;
}	
for(int i =0;i<n;i++){
	if(row-i <n and col+i<n)
		 if(a[row-i][col+i] == 'Q')return false;
}	
return true;
}
void N_queen_solution(int n,int row ){

	if(row == n){
		ans.push_back(a);
		return
	}
for(int i =0;i<n;i++){
	if(isvalid(n,row,i)){
		a[row][i] = 'Q';
		N_queen_solution(n,row+1);
			a[row][i] = '.'
	}
}
return ;
}
int main(int argc, char const *argv[])
{

return 0;	

}