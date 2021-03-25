//# Author : nuclear852 ========================#
//# Solution : 5147049 =========================#
//# Time Stamp : 2017-02-02 11:14:38 ===========#
//# Problem Title : 프로그램 ===================#
//# Language : C++98 ===========================#

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

vector <long long> tree(1000005);
map<int, long long> m;

long long sum(int i){
        long long ans = 0;
        while( i > 0) {
                ans += tree[i];
                i -= (i & -i);
        }
        return ans;
}

void update(int i, long long num){
        while( i<=1000005) {
                tree[i] += num;
                i += (i & -i);
        }
}

int main(){
        int N, K; cin>>N>>K;
        while(K--){
                int jump;
                scanf("%d",&jump);
                m[jump]++;
        }

        map<int,long long>::iterator iter;
        for(iter=m.begin(); iter!=m.end(); iter++){
                for(int j=1; j<=N; j+=iter->first)
                        update(j, iter->second);
        }

        int Q; cin>>Q;
        while(Q--){
                int L, R; scanf("%d %d",&L,&R);
                printf("%lld\n", sum(R+1) - sum(L));
        }
}