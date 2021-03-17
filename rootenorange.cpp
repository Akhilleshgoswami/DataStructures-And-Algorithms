// class Solution {
// public:
//    int orangesRotting(vector<vector<int>>& grid) {
//         queue<pair<int, int>> rotten;
//         int r = grid.size(), c = grid[0].size(), fresh = 0, t = 0;
//         for(int i = 0; i < r; ++i){
//             for(int j = 0; j < c; ++j){
//                 if(grid[i][j] == 2) rotten.push({i, j});
//                 else if(grid[i][j] == 1) fresh++;
//             }
//         }
        
//         while(!rotten.empty()){
//             int num = rotten.size();
//             for(int i = 0; i < num; ++i){
//                 int x = rotten.front().first, y = rotten.front().second;
//                 rotten.pop();
//                 if(x > 0 && grid[x-1][y] == 1){ grid[x-1][y] = 2; fresh--; rotten.push({x-1, y});};
//                 if(y > 0 && grid[x][y-1] == 1){ grid[x][y-1] = 2; fresh--; rotten.push({x, y-1});};
//                 if(x < r-1 && grid[x+1][y] == 1){ grid[x+1][y] = 2; fresh--; rotten.push({x+1, y});};
//                 if(y < c-1 && grid[x][y+1] == 1){ grid[x][y+1] = 2; fresh--; rotten.push({x, y+1});};
//             }
//             if(!rotten.empty()) t++;
//         }
//         return (fresh == 0) ? t : -1;
//     }
// };
#include<bits/stdc++.h>
using namespace std;
int orangesRottind(int arr[4][4]){
    int fresh = 0;
queue<pair<int,int>>rotten;
for(int  i =0;i<4;i++){
    for(int j =0;j<4;j++){
        if(arr[i][j]== 2)rotten.push({i,j});
        else if(arr[i][j] == 1)fresh++;
    }
}
int t = 0;
while(!rotten.empty()){
    cout<<rotten.size();
    int num = rotten.size();
    for(int i=0;i<4;i++){
        int x = rotten.front().first;
        int y = rotten.front().second;
        rotten.pop();
        if(x>0 and arr[x-1][y]==1){arr[x-1][y] =2; fresh--; rotten.push({x-1,y});}
          if(x<3and arr[x+1][y]==1){arr[x+1][y] =2; fresh--; rotten.push({x+1,y});}
            if(y>0 and arr[x][y-1]==1){arr[x][y-1] =2; fresh--; rotten.push({x,y-1});}
              if(y<3 and arr[x][y+1]==1){arr[x][y+1] =2; fresh--; rotten.push({x,y+1});}
    }
    if(!rotten.empty())t++;
}
return (fresh ==0) ? t : -1;
}
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[4][4] {
        {2,1,1,2},
        {1,0,0,1},
        {1,1,0,0},
        {2,1,1,2},
    };
 cout<<orangesRottind(arr);
    return 0;
}