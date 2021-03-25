//# Author : nuclear852 ========================#
//# Solution : 5022811 =========================#
//# Time Stamp : 2017-01-15 14:32:44 ===========#
//# Problem Title : 계단 오르기 =================#
//# Language : C++98 ===========================#

#include<iostream>
#include<cstdio>
using namespace std;

int dpp[301]={0};
int stair[301]={0};

/*int dp(int state, int pos, int vol[], int n){
	
	if(pos==n-1)	return stair[n-1];
	else if(pos==1){
		if(state==1)	return vol[pos];
		else
			return dp(1,0,vol,n)+vol[pos];
	}
	else if(pos==0)		return vol[pos];
	else if(pos > 1){
		if(state==0)
			return (max(dp(1,pos-1,vol,n), dp(0,pos-2,vol,n))+vol[pos]);
		else
			return vol[pos]+dp(0,pos-2,vol,n);
	
	}
	
	else	return 0;
	
}*/

int dp(int n){
	if(n==1)	return stair[1];
	if(n==2)	return  stair[2]+max(stair[1],0 );
	if(n==3)	return stair[3]+ max(stair[1],stair[2]);
    if(dpp[n] != 0)
        return dpp[n];
	if(n-3>0){
	for(int i=1;i<=n;i++)
	dpp[n]= stair[n]+ max(dp(n-2),dp(n-3)+stair[n-1]);
		}
	return dpp[n];
	
}


int main(){
	
	int num;
	cin>>num;
	
	
	for(int i=1;i<=num;i++){
		scanf("%d", &stair[i]);
	}
	
		printf("%d",dp(num));

	return 0;
}