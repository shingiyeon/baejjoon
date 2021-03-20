#include <stdio.h>
int arr[100];
int main(){
	int N; scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	for(int i=1; i<N; i++){
		int a = arr[0], b = arr[i];
		if(b>a){long long temp = b; b = a; a = temp;}
		long long ta = a, tb = b;
		while(ta%tb){ long long temp = ta % tb; ta = tb; tb = temp;}
		printf("%d/%d\n",arr[0]/tb,arr[i]/tb);
	}
}
