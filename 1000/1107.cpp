#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int K;
int d[1000001];
vector<int> e;
int min(int x, int y){
	return x < y? x : y;
}

int main(){
	int f; scanf("%d%d", &f,&K);
	for(int i=0; i<K; i++) {int tmp; scanf("%d",&tmp); e.push_back(tmp);}
	for(int i=0; i<=1000000; i++){
		int idx = 0; int temp = i;
		do{
			for(int j=0; j<e.size(); j++){
				if(temp%10 == e[j]){
					idx = -1;
					break;
				}
			}
			if(idx==-1) break;
			temp = temp/10;
			idx++;
		}while(temp);
		d[i] = idx;
	}
	int minvalue = f > 100? f-100: 100-f;
	for(int i=0; i<=1000000; i++){
		int temp = 1000000000;
		if(d[i]!=-1){
			temp = f > i? (f-i)+d[i] : (i-f)+d[i];
		}
		if(f>100)temp = temp > f-100? f-100 : temp;
		else temp = temp > 100-f? 100-f : temp;
		minvalue = minvalue > temp? temp : minvalue;
	}
	printf("%d", minvalue);
}
