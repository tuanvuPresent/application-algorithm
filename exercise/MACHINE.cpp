/*
An engineer needs to schedule a machine to run on some given periods 1,�,n
to produce a chemical product CC. Each period i is represented by a starting time point si
and terminating time point titi (si<tisi<ti). 
Due to a technical constraint, the machine must run on exactly two periods that are not overlap 
(two periods ii and jj are not overlap if ti<sjti<sj or tj<sitj<si). 
If the machine is runned on the period ii, then the amount of C 
it will produce is equal to the duration of the period ii (which is equal to ti-siti-si). 
Help the engineer to select two not-overlap periods to run the machine such that the amount of C produced is maximal.

Input
Line 1: contains the positive integer nn (2=n=106)
Line i+1i+1: contains two positive integer sisi and titi (1=si<ti=106)
Output
The output consists of only one single integer which is the amount of product CC the machine 
will produce in the two selected periods. In case there is no solution 
(there does not exist two periods that are not overlap), the output contains the value -1.

inputCopy
5
8 12
6 11
3 9
2 5
1 4
outputCopy
8
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001][2];
int f[1000001];

void solve(int n)
{
    //g1 [i] = max ( g1[i-1] ,... ) :cong viec thoi gian max ket thuc tai thoi diem i
}

int main()
{
    //input
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i][0] >> arr[i][1];
    //handle
    solve(n);
    //show output
    cout << res;

    return 0;
}
