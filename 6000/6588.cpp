#include <stdio.h>
#include <vector>
using namespace std;

vector<int> s;
bool sosu[1000001];
int n[1000001];
int main(){
	sosu[1] = 1;
	for(int i=2; i<=1000000; i++){
		if(sosu[i]) continue;
		for(int j=2; i*j<=1000000; j++)
			sosu[i*j] = 1;
	}
	for(int i=3; i<=1000000; i++)
		if(!sosu[i]) s.push_back(i);
	
	for(int i=6; i<=1000000; i++){
		printf("%d",i);
		for(int j=0; j<s.size(); j++){
			if(s[j]>i) break;
			if(!sosu[i-s[j]]){
				n[i] = s[j]; break;
			}
		}
	}
	
	printf("sosu");
	int T; scanf("%d", &T);
	while(T){
		printf("%d = %d + %d\n", T, n[T], T-n[T]);
	}
}
