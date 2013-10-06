#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int n,r,c,k;
int mat[200][200];
int mat2[200][200];
bool vis[200][200];
int dx[] = {0, 0,1, -1};//-1
int dy[] = {1,-1,0, 0};//0
vector<queue <pair<int,int> > > eat(200);
void mostrar(){
	for(int i=0;i<r;i++){
		cout<<mat2[i][0];
		for(int j=1;j<c;j++){
			cout<<" "<<mat2[i][j];
		}	
		cout<<endl;
	}
}

void dfs(int x,int y){
	//vis[x][y]=true;
	int d=mat[x][y];
	if(d!=n){
		for(int i=0;i<4;i++){
			int a=x+dx[i];
			int b=y+dy[i];
			if(a>=0 && b>=0 &&  a<r && b<c && !vis[a][b]){
				if(mat[a][b]==d+1){
					//dfs(a,b);
					mat2[a][b]=d;
				}
			}
		}
	}else{
		for(int i=0;i<4;i++){
			int a=x+dx[i];
			int b=y+dy[i];
			if(a>=0 && b>=0 &&  a<r && b<c && !vis[a][b]){
				if(mat[a][b]==0){
					//dfs(a,b);
					mat2[a][b]=n;
				}
			}
		}
	}
}

int main(){
	//freopen("4473.in","r",stdin);
	while(scanf("%d %d %d %d",&n,&r,&c,&k)==4){
		if(n==0 and r==0 and c==0 and k==0)break;
		n--;
		memset(mat,0, sizeof mat);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				scanf("%d",&mat[i][j]);
				mat2[i][j]=mat[i][j];
			}
		}
		while(k--){
			memset(vis,0, sizeof vis);
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					dfs(i,j);
				}
			}
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					mat[i][j]=mat2[i][j];
				}
			}
		}
		mostrar();
	}
	return 0;
}