/*

Vào dau hoc ky, truong phòng khoa hoc máy tính D phai phân công các khóa hoc cho giáo viên mot cách cân bang. 
Khoa D có m giáo viên T = {1,2, ..., m} và n khóa C = {1,2, ..., n}. 
Moi khóa hoc C có thoi luong hc. Moi giáo viên có mot danh sách uu tiên 
là danh sách các khóa h?c mà anh / cô ay có the day tùy thuoc vào chuyên môn cua mình. 
Chúng tôi biet mot danh sách các cap xung dot hai khóa hoc không the duoc chi danh cho cùng mot giáo viên 
vì các khóa hoc này dã duoc lên lich trong cùng mot thoi gian bieu. 
Thông tin xung dot này duoc bieu thi bang ma tran xung dot A 
trong dó A (i, j) = 1 chi ra rang khóa hoc i và j là xung dot. 
Tai cua giáo viên là tung thoi luong cua các khóa hoc duoc gán cho cô ay / anh ay. 
Làm the nào de gán các khóa hoc nn cho m giáo viên sao cho moi khóa hoc duoc chi danh 
cho mot giáo viên nam trong danh sách uu tiên cua anh ay / cô ay, 
không có hai khóa hoc xung dot nào duoc gán cho cùng mot giáo viên và tai toi da cua giáo viên là toi thieu.

input:
4 2
3 7 2 1	
2 1 2
2 1 2
2 1 2
2 1 2
0 0 0 1
0 0 0 0
0 0 0 1
1 0 1 0

ouput:
8

*/

#include <iostream>
using namespace std;
int soGiaoVien;
int soMon;
int p[21][6]= {0} ; // mon i co nhung giao vien nao day
int time[21]; // thoi gian cua mon
int matrix[21][21]; //matrix[i][j] = 1  ,i  j la 2 mon cung thoi gian day

int res = 1000000000;
int load[6]={0};
int X[21]={0};

int maxLoad()
{
    int max = load[1];
    for (int i = 2; i <= soGiaoVien; i++) {
        if(max < load[i]){
        	max = load[i];
		}
    }
    return max;
}

int check(int n, int v){
	if( p[n][v] == 0 ) return 0; 						// mon n giao vien v day
	for(int i = 1; i <= n - 1; i++){
		if(matrix[i][n] && X[i] == v ) return 0;
	}
	return 1;
}

void backtrack(int n)
{
    if (n == soMon + 1) {
        int temp = maxLoad();
        res = min(res, temp);
    }
    else {
        for (int v = 1; v <= soGiaoVien; v++) {
            if (check(n,v)) {
            	X[n] = v;
                load[v] += time[n];
                backtrack(n + 1);
                load[v] -= time[n];
            }
        }
    }
}

int main()
{
    //input
    cin >> soMon >> soGiaoVien;
    for (int i = 1; i <= soMon; i++)
        cin >> time[i];

    for (int i = 1; i <= soMon; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            p[i][x] = 1;
        }
    }

    for (int i = 1; i <= soMon; i++) {
        for (int j = 1; j <= soMon; j++) {
            cin >> matrix[i][j];
        }
    }
    //handle
    backtrack(1);
    //show output
    if(res == 1000000000){
    	cout<<"-1";
	}else{
		cout << res;
	}

    return 0;
}
