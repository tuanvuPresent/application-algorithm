/*
Tinh C(k,n) mod m

1
1000000000000000000
100000
1000000000000000009

input: 
2
7 3 7
5 2 7

output:
0
3

*/

#include <iostream>
#include <time.h>
using namespace std;

bool isPrime(long long n){
	long long i=2;
	while(i*i<=n){
		if(n%i==0){
			cout<<"false "<<i;
			return false;
		}
		i = i + 1;
	}
	cout<<"true";
	return true;
}

long long modulo_inverse(long long n, long long m)
{
    for (int i = 1; i < m; i++) {
        if (((long long)n * i) % m == 1) {
            return i;
        }
    }
    return -1; // not exist
}

long long gcd_extend(long long a, long long b, long long* x, long long* y)
{
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = gcd_extend(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

long long modulo_inverse_euclidean(long long n, long long m)
{
    long long x, y;
    if (gcd_extend(n, m, &x, &y) != 1)
        return -1; // not exist
    return (x % m + m) % m; // vì x có th? âm
}

long long modulo_combination(long long n, long long k, long long m)
{
    long long a = 1, b = 1, c = 1;
    for (int i = 2; i <= n; i++) {
        a = ((long long)a * i) % m;
    }
    for (int i = 2; i <= n - k; i++) {
        b = ((long long)b * i) % m;
    }
    for (int i = 2; i <= k; i++) {
        c = ((long long)c * i) % m;
    }
    b = ((long long)b * c) % m;
    return ((long long)a * modulo_inverse_euclidean(b, m)) % m;
}

int summod(int a, int b, int P)
{
    a %= P;
    b %= P;
    int d = P - b;
    // a + b = a + P -d 
    return a < d? a+b: a-d;
}

long long mulMod(long long a, long long b, long long m)
{
    // a * b mod m
    if (a == 0 || b == 0){
    	return 0;
	}
    if (b == 1) {
        return a % m;
    }
    if (b % 2 == 0) {
        long long x = mulMod(a, b / 2, m);
        return (x % m + x % m) % m;
    }
    else {
        long long x = mulMod(a, b / 2, m);
        return (a % m + x % m + x % m) % m;
    }
}

long long module(long long n, long long k, long long m)
{
    long long a = 1;
    for (int i = 0; i < k; i++) {
        // tich n * n-1 *...* n-k+1
        long long temp = (n - i) % m;
        if(temp > 1000000000 && a > 1000000000 ){
        	a = mulMod(a, temp, m);
		}else{
			a = (a * temp) % m;
		}	
    }

    long long b = 1;
    for (int i = 2; i <= k; i++) {
    	// k!
    	if(b > 1000000000){
    		b = mulMod(b,i,m);
		}else{
			b = ( b * i ) % m;
		}
    }
    // b = b ^ -1
	b = modulo_inverse_euclidean(b, m);
	
    return mulMod(a, b, m);
}

void QHD(int n, int k, int m)
{
    long long C1[10001] = { 0 };
    long long C2[10001] = { 0 };
    //C(k,n) = C (k,n-1) + C(k-1, n-1)
    for (int i = 2; i <= n + 1; i++) {
        C1[0] = 1;
        for (int j = 1; j < i; j++) {
            C2[j] = (C1[j - 1] % m + C1[j] % m) % m;
            //			cout<<C2[j]<<" ";
        }
        //		cout<<"\n";

        //copy array C2 to C1
        for (int j = 1; j < i; j++) {
            C1[j] = C2[j];
        }
    }
}

int main()
{
    int numTest;
    cin >> numTest;

    for (int tCase = 0; tCase < numTest; tCase++) {
        //input
        long long n, k, m;
        cin >> n >> k >> m;
        //handle
        long long res = module(n, k, m);
        //output
        cout << res << "\n";
    }

    return 0;
}
