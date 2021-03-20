#include <stdio.h>
#include <vector>
#include <algorithm>
#define MIN -999999999
using namespace std;

int dy[200001][6];

vector<int> s[6];
int idx[6];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int lo, hi, m; scanf("%d%d%d",&lo,&hi,&m);
	int x, y;
	while(m--){
		scanf("%d%d",&x,&y);
		s[x].push_back(y);
	} 
	for(int i=0; i<=200000; i++){
		for(int j=0; j<=5; j++){
			dy[i][j] = MIN;
		}
	}
	for(int i=0; i<=5; i++)
		sort(s[i].begin(), s[i].end(), cmp);


	for(int i=0; i<=s[0].size(); i++){
		dy[0][0] += s[0][i] >= 0? s[0][i] : 0;
	}

	for(int i=1; i<=5; i++){
		int pos = 0;
		for(int j=0; j<=200000; j++){
			if(j>i) {dy[j][i] = dy[j][i-1]; continue;}
			
			if(dy[j-i][i-1] + s[i][idx[i]] >= dy[j][i-1]){
				dy[j][i] = dy[j-i][i-1] + s[i][idx[i]];
				idx[i]++;
			}
		}
	}
}
