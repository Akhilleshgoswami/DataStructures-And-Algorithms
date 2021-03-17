#include<bits/stdc++.h>
using namespace std;
stack<int>main1;
stack<int>ss;
void push1(int n){
	

		main1.push(n);
	if(ss.empty()){
		ss.push(n);
	}
	// cout<<ss.top()<<n<<endl;
	if(ss.top()>n){
		ss.push(n);
	}
}
int pop1(){
	int x = main1.top();
	main1.pop();
	// cout<<x<<" "<<ss.top()<<endl;
	if(x == ss.top()){
		ss.pop();
	}
	return x;
}
int getmin1(){
	if(ss.empty())return 0;
	return ss.top();
}

int main(){
push1(13);
push1(5);
push1(3);
push1(6);
pop1();
pop1();

push1(13);
cout<<getmin1();
	return 0;
}