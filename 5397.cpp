#include <stdio.h>
#include <vector>

using namespace std;

char str[1000005];
vector<char> v;

int main(){
    int T; scanf("%d", &T);
    while(T--){
        v.clear();
        scanf("%s", str);
        int strlen = 0;
        for(strlen=0; str[strlen]!='\0'; strlen++);
        int idx = 0;
        for(int i=0; i<strlen; i++){
            if(str[i]=='<'){
                idx = idx == 0? 0 : idx-1;
            }
            else if(str[i] == '>'){
                idx = idx == v.size()? v.size(): idx+1; 
            }
            else if(str[i] == '-'){
                if(idx == 0) continue;
                idx -= 1;
                v.erase(v.begin()+idx);
            }
            else{
                v.insert(v.begin()+idx, str[i]);
                idx++;
            }
        }
        for(int i=0; i<v.size(); i++){
            printf("%c",v[i]);
        }
        printf("\n");
    }
}
