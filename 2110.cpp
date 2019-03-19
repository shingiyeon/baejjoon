#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int MAX = 0;
vector<int> v;
int N, C;

int max(int a, int b){
    return a > b? a : b;
}

bool find_pos(int c){
    int num = 1;
    int idx = 1;
    int x = v[0];

    while(idx < N){

        if ( v[idx] - x >= c){
            num++;
            x = v[idx];
            idx++;
        }

        else{
            idx++;
        }
    }

    if(num >= C){
        return 1;
    }

    else{
        return 0;
    }
}

void find_max(int s, int e){
    if(s>e) return;
    int mid = (s+e)/2;
    if(find_pos(mid)){
        MAX = mid;
        find_max(mid+1, e);
    }
    else{
        find_max(s, mid-1);
    }

}

int main(){
    
    scanf("%d %d", &N, &C);
    for(int i=0; i<N; i++){
        int t; scanf("%d", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    find_max(1, 1000000000);
    printf("%d", MAX);
}
