#include<bits/stdc++.h>
using namespace std;
std::vector<std::vector<int>> ans;
void combinationsum(int arr[], int n,int index,int size,std::vector<int> ds){
if(index == size){
if(n==0){
	ans.push_back(ds);
}
return;

}
if(arr[index] <=n){
	ds.push_back(arr[index]);
	combinationsum(arr,n-arr[index],index,size,ds);
ds.pop_back();
}
combinationsum(arr,n,index+1,size,ds);
}


int main(int argc, char const *argv[])
{
	int arr[] ={2,3,1,4};
	int n =7;

std::vector<int> v;
combinationsum(arr,n,0,4,v);
for(int i =0;i<ans.size();i++){
for(int j = 0;j<ans[i].size();j++){
	cout<<ans[i][j]<<" ";
}
cout<<endl;
	
}return 0;
}