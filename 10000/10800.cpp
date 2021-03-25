//# Author : nuclear852 ========================#
//# Solution : 12938431 ========================#
//# Time Stamp : 2019-04-27 13:06:37 ===========#
//# Problem Title : 컬러볼 ====================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <vector>
using namespace std;
struct ball{
	int num;
	int color;
	int size;
};

vector<ball> s[2005];
int color[200005];
int sum[200005];
int main(){
	int hap = 0;
	int N; scanf("%d", &N);
	for(int i=1; i<=N; i++){
		struct ball temp;
		scanf("%d%d",&temp.color, &temp.size);
		temp.num = i;
		s[temp.size].push_back(temp);
	}
	for(int i=1; i<=2000; i++){
		for(int j=0; j<s[i].size(); j++){
			sum[s[i][j].num] = hap - color[s[i][j].color];
		}
		for(int j=0; j<s[i].size(); j++){
			hap += s[i][j].size;
			color[s[i][j].color] += s[i][j].size;
		}
	}
	for(int i=1; i<=N; i++){
		printf("%d\n", sum[i]);
	}
}