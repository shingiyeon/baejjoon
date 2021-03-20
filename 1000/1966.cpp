#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

vector< pair<int, int> > v;

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N); int num; scanf("%d", &num);
		for(int i=0; i<N; i++){
			pair<int, int> p; p.first = i; scanf("%d", &p.second);
			v.push_back(p); 
		}
		int idx = 1;
		while(1){
			int max = (1<<31);
			for(int i=0; i<v.size(); i++){
				if(v[i].second > max) max = v[i].second;
			}
			int value = v[0].second;
			while(value!=max){
				v.push_back(v[0]);
				v.erase(v.begin());
				value = v[0].second;
			}
			if(v[0].first == num){
				break;
			}
			else{
				idx++;
				v.erase(v.begin());
			}
		}
		while(!v.empty()) v.pop_back();
		printf("%d\n", idx);
	}
}
