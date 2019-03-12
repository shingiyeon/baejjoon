#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct girlgroup{
	char n[101];
	string name[100];
	int number;
}g[100];

int strlen(string a){
	int i=0;
	for(i=0; a[i]!='\0'; i++);
	return i;
}

bool comp(string a, string b){
	if(strlen(a) != strlen(b)) return 0;
	for(int i=0; i<strlen(a); i++)
		if(a[i]!=b[i]) return 0;
	return 1;
}

bool c(string a, string b){
	int len = strlen(a) < strlen(b) ? strlen(a) : strlen(b);
	for(int i=0; i<len; i++){
		if(a[i] < b[i]) return 1;
		else if(a[i] > b[i]) return 0;
	}
	if(strlen(a) < strlen(b)) return 1;
	return 0;
}

int main(){
	int N, M; scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++){
		scanf("%s", g[i].n);
		scanf("%d", &g[i].number);
		for(int j=0; j<g[i].number; j++){
			cin>>g[i].name[j];
		}
		sort(g[i].name, g[i].name+g[i].number, c);
	}
	for(int i=0; i<M; i++){
		string name; cin>>name;
		int a; scanf("%d", &a);
		if(a){
			for(int j=0; j<N; j++){
				bool pos = 0;
				for(int k=0; k<g[j].number; k++){
					if(comp(name, g[j].name[k])){
						cout<<g[j].n<<endl;
						pos = 1; break;
					}
				}
				if(pos) break;
			}
		}
		else{
			for(int j=0; j<N; j++){
				if(comp(name, g[j].n)){
					for(int k=0; k<g[j].number; k++){
						cout<<g[j].name[k]<<endl;
					}
					break;
				}
			}
		}
	}
}
