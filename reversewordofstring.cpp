// class Solution {
// public:
//     string reverseWords(string s) {
//         string result;
//     int i = 0;
//     int n = s.length();

//     while(i < n){
//         while(i < n && s[i] == ' ') i++;
//         if(i >= n) break;
//         int j = i + 1;
//         while(j < n && s[j] != ' ') j++;
//         string sub = s.substr(i, j-i);
//         if(result.length() == 0) result = sub;
//         else result = sub + " " + result;
//         i = j+1;
//     }
//     return result;

//     }
// };
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string reverserword(string s ){
    int length = s.size();
    string  result = "";
int i = 0;
while(i<length ){
    while(i<length and s[i]==' ')i++;

    if(i>=length)break;

    int j = i+1;
    
    while(j<length and s[j]!=' ')j++;

        string sub = s.substr(i,j-i);
        if(result.size() == 0) result = sub;

        else result =  sub +" "+result;
        i =j+1;
    
}
return result;
}
int main(){
    cout<<reverserword("hello World");
    return 0;
}