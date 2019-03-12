#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int a[4][4000];
vector<int> v0;
vector<int> v1;
long long ans = 0;

int main(){
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<4; j++)
			scanf("%d",&a[j][i]);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			v0.push_back(a[0][i]+a[1][j]);
			v1.push_back(a[2][i]+a[3][j]);
		}
	}
	sort(v0.begin(),v0.end());
	sort(v1.begin(),v1.end());
	int low, up;
	for(int i=0; i<v0.size(); i++){
		if(binary_search(v1.begin(), v1.end(), -v0[i])){
			low = lower_bound(v1.begin(), v1.end(), -v0[i]) - v1.begin();
			up = upper_bound(v1.begin(), v1.end(), -v0[i]) - v1.begin();
			ans += up-low;
		}
	}
	printf("%lld", ans);
}
