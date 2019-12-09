/*
My birthday is coming up and traditionally I'm serving pie.
Not just one pie, no, I have a number N of them, of various tastes and of various sizes.
F of my friends are coming to my party and each of them gets a piece of pie.
This should be one piece of one pie, not several small pieces since that looks messy.
This piece can be one whole pie though.
My friends are very annoying and if one of them gets a bigger piece than the others, they start complaining.
Therefore all of them should get equally sized
(but not necessarily equally shaped) pieces, even if this leads to some pie getting spoiled
(which is better than spoiling the party). Of course, I want a piece of pie for myself too,
and that piece should also be of the same size. What is the largest possible piece size all of us can get?
All the pies are cylindrical in shape and they all have the same height 1, but the radii of the pies can be different.

Input
One line with a positive integer: the number of test cases. Then for each test case:

One line with two integers N and F with 1F=N,F=10000: the number of pies and the number of friends.
One line with NN integers riri with 1 <= ri <= 10000: the radii of the pies.
Output
For each test case, output one line with the largest possible volume
VV such that me and my friends can all get a pie piece of size VV.
The answer should be given as a floating point number rounding to 6 digits after the floating point.
*/

#include <iostream>
#include <algorithm>
#include <math.h>
const double PI = 2*acos(0.0);
using namespace std;

double V[10001];

void solve() {
	int n,f;
	cin>>n>>f;
	for(int i=0; i<n; i++) {
		int x;
		cin>>x;
		V[i] = (x * x) * PI;
		printf("%.6f ",V[i]);
	}
}

int main() {
	int numTest;
	cin>>numTest;
	for(int tCase=1; tCase<=numTest; tCase++) {
		solve();
	}

	return 0;
}

