//# Author : nuclear852 ========================#
//# Solution : 11982639 ========================#
//# Time Stamp : 2019-03-02 02:55:42 ===========#
//# Problem Title : 인구 이동 ==================#
//# Language : C++98 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int N, L, R;
int map[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool match[100][100][4];
bool visited[100][100];
int ans;

int main(){
	scanf("%d%d%d", &N,&L,&R);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			scanf("%d", &map[i][j]);
	}
	while(1){
		int num = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				visited[i][j] = 0;
				for(int k=0; k<4; k++){
					match[i][j][k] = 0;
				}
			}
		}
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				for(int k=0; k<4; k++){
					if(i+dx[k]<0||i+dx[k]>=N||j+dy[k]<0||j+dy[k]>=N)
						continue;
					int temp = map[i][j]-map[i+dx[k]][j+dy[k]];
					if(temp<0) temp = -temp;
					if(temp>=L && temp<=R){
						match[i][j][k] = 1;
						num++;
					}
				}
			}
		}
		
		if(!num) break;
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				bool pos = 0;
				for(int k=0; k<4; k++)
					if(match[i][j][k]==1) pos = 1;
				if(pos&&!visited[i][j]){
					vector<pair<int,int> > v;
					queue< pair<int, int> > q;
					visited[i][j] = 1;
					q.push(pair<int,int>(i,j));
					while(!q.empty()){
						int x = q.front().first;
						int y = q.front().second;
						v.push_back(q.front());
						q.pop();
						for(int k=0; k<4; k++){
							if(x+dx[k]<0||x+dx[k]>=N||y+dy[k]<0||y+dy[k]>=N)
								continue;
							if(visited[x+dx[k]][y+dy[k]]) continue;
							if(!match[x][y][k]) continue;
							visited[x+dx[k]][y+dy[k]] = 1;
							q.push(pair<int, int>(x+dx[k],y+dy[k]));
						}
					}
					int sum = 0;
					for(int k=0; k<v.size(); k++)
						sum += map[v[k].first][v[k].second];
					sum /= v.size();
					for(int k=0; k<v.size(); k++)
						map[v[k].first][v[k].second] = sum;
				}

			}
		}
		ans++;
	}
	printf("%d", ans);
}