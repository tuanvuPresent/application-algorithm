/*
Cho NN di?m trên m?t ph?ng, hãy tìm m?t c?p di?m v?i kho?ng cách euclid nh? nh?t gi?a chúng. 
Bi?t r?ng không có hai di?m nào trùng nhau và có duy nh?t m?t c?t có kho?ng cách nh? nh?t.
 
Input
Dòng d?u tiên ch?a m?t s? nguyên NN (2=N=50000). 
NN dòng ti?p theo m?i dòng ch?a hai s? nguyên là t?a d? XX và YY c?a m?t di?m. 
Giá tr? tuy?t d?i c?a XX, YY không vu?t quá 106106.
 
Output
Ghi ra 3 s? abc, trong dó a,b (a<b) là các ch? s? c?a c?p di?m tìm du?c 
trong d? li?u vào (ch? s? b?t d?u t? 0) và cc là kho?ng cách gi?a chúng. Làm tròn cc d?n 6 ch? s? sau d?u ph?y d?ng.
 
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
 
double euclid(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
 
bool cmpX(Point p1, Point p2)
{
    return p1.x < p2.x;
}
 
void find(int left, int right)
{
    if (left >= right)
        return;
 
    if (left == right - 1) {
        double temp = euclid(p[left], p[right]);
        if (temp < res) {
            res = temp;
            if (p[left].vt < p[right].vt) {
                a = p[left].vt;
                b = p[right].vt;
            }
            else {
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
    int d = (int)( res + 1 );
    int midx = p[m].x; 
    for (int i = left; i <= right ; i++) 
		if (abs(p[i].x-midx) <= d){
        for (int j = left; j <= right && i != j; j++) {
            if (euclid(p[i], p[j]) < res) {
                res = euclid(p[i], p[j]);
                if (p[i].vt < p[j].vt) {
                    a = p[i].vt;
                    b = p[j].vt;
                }
                else {
                    a = p[j].vt;
                    b = p[i].vt;
                }
            }
        }
    }
}
 
int main()
{
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
