#include<iostream>
#include<string.h>

/*
Hình ?nh ch?p t? v? tinh vùng bi?n Atlantic g?m nhi?u hòn d?o du?c chia nh? thành các lu?i ô vuông. 
Máy quang h?c s? ti?n hành quét t?ng lu?i ô vuông, và ti?n hành tô màu d? n?u ô dó có ch?a d?t c?a hòn d?o nào dó, 
và tô màu xanh n?u không có hòn d?o nào n?m trong nó. Hãy:

* Ð?m s? hòn d?o có trong ?nh

* Ðua ra di?n tích c?a hòn d?o l?n nh?t (= s? lu?ng lu?i ô vuông ch?a hòn d?o l?n nh?t)

Input
Dòng d?u tiên ch?a hai s? nguyên duong n,m<=1000n.

Các dòng ti?p theo bi?u di?n lu?i ô vuông nhu ví d?.

Output
G?m hai dòng:

Dòng d?u tiên ch?a s? lu?ng hòn d?o trong ?nh.

Dòng th? hai ch?a di?n tích c?a hòn d?o l?n nh?t nhu miêu t?.

input:
7 11
00000000010
11100000000
00000111100
00111111110
00111111110
00111111000
00000110000

output:
3
28

*/

using namespace std;

char matrix[1001][1001];
int visit[1001][1001] = {0};
int res, count;
void DFS(int x, int y){
	if(matrix[x][y] == '1' && visit[x][y] == 0){
		count++;
		visit[x][y] = 1;
		
		DFS(x + 1, y);
		DFS(x - 1, y);
		DFS(x, y + 1);
		DFS(x, y - 1);
	}
}

int main(){
	//input
	memset(matrix, '0', sizeof(matrix));
	int row, col; cin>>row>>col;
	for(int i=0; i< row; i++){
		cin>>matrix[i];
	}
			
	//handle
	int soDao = 0;
	for(int i=0; i< row; i++){
		for(int j=0; j< col; j++){
			if(matrix[i][j] == '1' && visit[i][j] == 0){
				soDao++;
				
				count = 0;
				DFS(i, j);
				res = max(res, count);	
			}	
		}
	}
	//show output
	cout<<soDao<<"\n"<<res;
	
	return 0;
}
