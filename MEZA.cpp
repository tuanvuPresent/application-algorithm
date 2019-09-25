#include <iostream>
#include <string.h>

using namespace std;
int matrix[901][901];
int visit[901][901];
//queen
int q[900000][3];
int fisrt, last;
int x, y, z;
void add(int x, int y){
	q[last][0] = x;
	q[last][1] = y;
	q[last][2] = z + 1;
	last++;
}
void pop(){
	x = q[fisrt][0];
	y = q[fisrt][1];
	z = q[fisrt][2];
	fisrt++;
}

void BFS(int sx,int sy, int n, int m){
	//initial
	matrix[sx][sy] = 0;
	fisrt = 0;
	last = 0;
	z = 0;
	memset(visit, 0, sizeof(visit));
	
	add(sx,sy);
	visit[sx][sy] = 1;
	bool timThay =false;
	
	while(fisrt!=last){
		pop();
		//kiem di den dich
		if(x== n || x==1 || y==1 || y==m){
			timThay = true;
			break;
		}
		if( x + 1 <= n && matrix[x+1][y] == 0  && visit[x+1][y] == 0 ){
			add(x+1,y);
			visit[x+1][y] = z+1;
		}
		if( x - 1 >= 1 && matrix[x-1][y] == 0  &&visit[x-1][y] == 0 ){
			visit[x-1][y] = z+1;
			add(x-1,y);
		}
		if( y + 1 <=m && matrix[x][y+1] == 0  &&visit[x][y+1] == 0 ){
			visit[x][y+1] = z+1;
			add(x,y+1);
		}
		if( y - 1 >=1 && matrix[x][y-1] == 0  &&visit[x][y-1] == 0 ){
			visit[x][y-1] = z+1;
			add(x,y-1);
		}
	}
	
	if(timThay){
		cout<<z<<"\n";
	}else{
//		cout<<"NO\n";
		cout<<-1;
	}	
}

int main(){
	//input
	int n,m; cin>>n>>m;
	int sx, sy; cin>>sx>>sy;
	for(int i=1 ; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>matrix[i][j];
		}
	}
	//handle
	//di tu toa do (sx,sy) 
	BFS(sx,sy,n,m);
//	for(int i=1 ; i<=n; i++){
//		for(int j=1; j<=m ;j++){
//			cout<<visit[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	return 0;
}
