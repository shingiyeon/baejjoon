#include <stdio.h>
#include <stack>
#include <utility>
using namespace std;
typedef pair<int, int> p;
int main(){
  int N; scanf("%d", &N);
  stack<p> s;
  for(int i=1; i<=N; i++){
      pair<int, int> temp;
      scanf("%d", &temp.first);
      temp.second = i;
      while(!s.empty() && s.top().first > temp.first){
          s.pop();
      }
      if(!s.empty()){
          printf("%d ", s.top().second);
      }
      else{
          printf("0 ");
      }
      s.push(temp);
  }
}
