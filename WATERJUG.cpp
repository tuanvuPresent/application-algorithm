
#include <iostream>
#include <string.h>

using namespace std;
/*
There are two jugs, a a-gallon one and a b-gallon one 
(a,b are positive integer). There is a pump with unlimited water. 
Neither jug has any measuring marking on it. 
How can you get exactly c c-gallon jug (c is a positive integer)?

Input
The input file consists of several datasets. 
The first line of the input file contains the number of datasets 
which is a positive integer TT and is not greater than 1000. 
Each of TT following lines consists 3 positive integer numbers 
a,b,c <= 10^8.

Output
For each dataset, write in one line one integer 
which is the minimum number of water movement steps to get cc gallon. 
Write -1 if there is no way to get cc.
*/

//----------------------------------- Cach 1: BFS chua dung -----------------------------------
int qx[1001000], qy[1001000];
int fist, last;
int qz[1001][1001];
int a, b, c;
int x=0, y=0, z=0;

bool pop()
{
    if (fist > last) {
        return false;
    }
    x = qx[fist];
    y = qy[fist];
    z = qz[x][y] + 1;
    fist++;

    return true;
}

int checkAndPush(int tx, int ty)
{
    if (tx == c || ty == c) {
        cout <<z<<"\n";
        return z;
    }
    else if (tx == 0 && ty == 0 || qz[tx][ty] > 0) {
        return 0;
    }
    else {
        last++;
        qx[last] = tx;
        qy[last] = ty;
        qz[tx][ty] = z;
        return 0;
    }
}

void solveTestCase()
{
    cin >> a >> b >> c;

    fist = 0;
    last = 0;
    qx[fist] = 0;
    qy[last] = 0;
    z=0;
    memset(qz,0,sizeof(qz));

    int t=0;

    while (pop()) {
        if (checkAndPush(0, y)) {
            return;
        }
        if (checkAndPush(x, 0)) {
            return;
        }

        if (checkAndPush(a, y)) {
            return;
        }
        if (checkAndPush(x, b)) {
            return;
        }

        t = min(x, b - y);
        if (checkAndPush(x - t, y + t)) {
            return;
        }
        t = min(a - x, y);
        if (checkAndPush(x + t, y - t)) {
            return;
        }
    }

    cout << "-1\n";
}
// ------------------------------------------------- Cach 2 ----------------------------------------
int gcd(int a, int b){
	int res = 1;
	while(a * b != 0){
		if(a > b){
			a %= b;
		}else{
			b %= a;
		} 
	}
	return a+b;
}

long long water(int a, int b, int c)
{
    if (c > a && c > b)
        return -1;
    if ((c % gcd(a,b)) != 0) 
        return -1; 
	if(a == 0 || b==0){
		return (a + b == c)? 1 : -1;
	}
    /*
    - neu x = 0 --> x = a
	- neu x > 0 --> k = min (x, b - y) x -=k, y+=k   
	- neu y = b --> y = 0   
	
    */
    long long step = 0;
	int x = 0, y = 0;
   
    do{
        if (y == b) {
            y = 0;
            step++;
        }
        if (x == 0) {
            x = a;
            step++;
        }
        if (x > 0) {
            int k = min(x, b - y);
            x -= k;
            y += k;
            step++;
        } 
        if(x == a && b==0){
        	//mul 
        	if(a>b){
				int soLan = a/b;
				x = a % b;
				y =0;
				step = step + soLan * 2;        		
			}else if(b>a){
				int soLan = b / a + 1;
				x = a * soLan - b; 
				y = b;
				step = step + soLan * 2 -1;
			}
		}
        
        if(x == c || y == c){
        	break;
		}
		if(x==0 && y==0){
			step = -1; // no solution
		}
		
    } while(x != 0 || y != 0);
	
	//ouput
	return step;
}

int main()
{	
    //input
//    int n;
//    cin >> n;
//    for (int tCase = 0; tCase < n; tCase++) {
        int a1,b1,c1; cin>>a1>>b1>>c1;
        //handle
        long long res = min(water(a1, b1, c1), water(b1, a1, c1));
        //show output
       	cout<<res<<"\n";

//		solveTestCase();
//    }

    return 0;
}

