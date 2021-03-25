//# Author : nuclear852 ========================#
//# Solution : 5068615 =========================#
//# Time Stamp : 2017-01-20 19:56:50 ===========#
//# Problem Title : 상근이의 여행 ================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int T; cin>>T;
	while(T--){
		int N; int M; int t1, t2;
		cin>>N>>M;
		for(int i=0; i<M; i++)	scanf("%d %d",&t1,&t2);
		cout<<N-1<<'\n';
	}
}