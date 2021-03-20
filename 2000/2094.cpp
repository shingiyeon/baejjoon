#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
vector< pair<int, int> > v;
int binary_search(int x, int s, int e){
	int mid = (s+e)/2;
	if(s>e) return s;
	if(x==v[mid].first) return mid;
	if(v[mid].first>x) return binary_search(x, s, mid-1);
	return binary_search(x, mid+1, e);	

}
int main(){
	int n; scanf("%d", &n);
	int a, b;
	for(int i=1; i<=n; i++){
		scanf("%d%d",&a,&b);
		v.push_back(pair<int, int>(a,b));
	}
	int m; scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d%d",&a,&b);
		int start = binary_search(b, 0, v.size()-1);
		int end = binary_search(a, 0, v.size()-1);
		printf("start: %d, end: %d, b: %d\n ", start, end, b);
		int pos = 0;
		for(int j=1; j<start-end; j++){
			printf("start: %d, end: %d, b: %d\n ", start, end, b);
			if(b-j != v[start-j].first) pos = 1;
			if(v[start-j].second > v[start].second){
				pos = -1; break;
			}
		}
		if(pos==0){
			printf("true\n");
		}
		if(pos==1){
			printf("maybe\n");
		}
		if(pos==-1){
			printf("false\n");
		}
	}
}
