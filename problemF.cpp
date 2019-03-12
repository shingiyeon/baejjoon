#include <stdio.h>
int arr[300001];
int color[300001][3];
int parent[300001];
int main(){
	int ans = 0;
	int n; scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
	for(int i=1; i<=n-1; i++){
		int a, b; scanf("%d%d",&a,&b);
		if(a>b) parent[a] = b;
		else parent[b] = a;
	}
	
	for(int i=1; i<=n; i++){
		int idx = i;
		color[i][arr[i]]++;
		while(parent[idx]!=0){
			idx = parent[idx];
			color[idx][arr[i]]++;
		}
	}
	
	for(int i=2; i<=n; i++){
		int red1 = color[1][1] - color[i][1];
		int blue1 = color[1][2] - color[i][2];
		
		if(red1==0&&blue1>0&&color[i][1]>0&&color[i][2]==0) ans++;
		else if(red1>0&&blue1==0&&color[i][1]==0&&color[i][2]>0) ans++;
	}
	printf("%d", ans);
	
}
