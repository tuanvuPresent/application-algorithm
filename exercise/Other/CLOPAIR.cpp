/*
Cho NN di?m tr�n m?t ph?ng, h�y t�m m?t c?p di?m v?i kho?ng c�ch euclid nh? nh?t gi?a ch�ng.
Bi?t r?ng kh�ng c� hai di?m n�o tr�ng nhau v� c� duy nh?t m?t c?t c� kho?ng c�ch nh? nh?t.

Input
D�ng d?u ti�n ch?a m?t s? nguy�n NN (2=N=50000).
NN d�ng ti?p theo m?i d�ng ch?a hai s? nguy�n l� t?a d? XX v� YY c?a m?t di?m.
Gi� tr? tuy?t d?i c?a XX, YY kh�ng vu?t qu� 106106.

Output
Ghi ra 3 s? abc, trong d� a,b (a<b) l� c�c ch? s? c?a c?p di?m t�m du?c
trong d? li?u v�o (ch? s? b?t d?u t? 0) v� cc l� kho?ng c�ch gi?a ch�ng. L�m tr�n cc d?n 6 ch? s? sau d?u ph?y d?ng.

input:
5
0 0
0 1
100 45
2 3
9 9

output:
0 1 1.000000

*/

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
struct Point {
	long long x;
	long long y;
	int vt;
};
Point p[50001];
double res;
int a, b;

double euclid(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool cmpX(Point p1, Point p2) {
	return p1.x < p2.x;
}

void find(int left, int right) {
	if (left >= right)
		return;

	if (left == right - 1) {
		double temp = euclid(p[left], p[right]);
		if (temp < res) {
			res = temp;
			if (p[left].vt < p[right].vt) {
				a = p[left].vt;
				b = p[right].vt;
			} else {
				a = p[right].vt;
				b = p[left].vt;
			}
		}
		return;
	}
	int m = left + (right - left) / 2;
	find(left, m);
	find(m, right);

	//find
	int d = (int)(res + 1);
	int midx = p[m].x;
	for (int i = left; i <= right; i++)
		if (abs(p[i].x - midx) <= d) {
			for (int j = left; j <= right && i != j; j++) {
				if (euclid(p[i], p[j]) < res) {
					res = euclid(p[i], p[j]);
					if (p[i].vt < p[j].vt) {
						a = p[i].vt;
						b = p[j].vt;
					} else {
						a = p[j].vt;
						b = p[i].vt;
					}
				}
			}
		}
}

int main() {
	//input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].vt = i;
	}

	//handle
	res = euclid(p[0], p[1]);
	a = 0;
	b = 1;
	sort(p, p + n, cmpX);
	//	for(int i=0; i<n;i++){
	//		for(int j= i+1; j<n;j++){
	//			double temp = euclid(p[i],p[j]);
	//			if(temp<res){
	//				res = temp;
	//				a = i;
	//				b = j;
	//			}
	//		}
	//	}

	find(0, n - 1);
	//show output
	printf("%d %d %0.6lf", a, b, res);

	return 0;
}
