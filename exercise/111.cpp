#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;

char output[22];
int matrix[10][10];
int visit[10][10];

int queen[1000][3];
int fisrt = 0, last = 0;
int x, y, z;
void popQ()
{
    x = queen[fisrt][0];
    y = queen[fisrt][1];
    z = queen[fisrt][2];
    fisrt++;
}

void addQ(int tx, int ty)
{
    queen[last][0] = tx;
    queen[last][1] = ty;
    queen[last][2] = z + 1;
    last++;
}

void showMatrix()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }
}

void BFS(int n)
{
    memset(matrix, -1, sizeof(matrix));
    memset(visit, 0, sizeof(visit));
    addQ(5, 5);
    z = 0;
    while (fisrt != last && n > 0)
    {
        n--;
        popQ();
        matrix[x][y] = z;
        if (matrix[x + 1][y] == -1)
        {
            matrix[x + 1][y] = z + 1;
            addQ(x + 1, y);
        }
        if (matrix[x - 1][y] == -1)
        {
            matrix[x - 1][y] = z + 1;
            addQ(x - 1, y);
        }
        if (matrix[x][y - 1] == -1)
        {
            matrix[x][y - 1] = z + 1;
            addQ(x, y - 1);
        }
        if (matrix[x][y + 1] == -1)
        {
            matrix[x][y + 1] = z + 1;
            addQ(x, y + 1);
        }
    }
    showMatrix();
}

void toHop(int n, int open, int close)
{
    if (open == n && close == n)
    {
        for (int i = 1; i <= n + n; i++)
            cout << output[i];
        cout << "\n";
        return;
    }
    if (open < n && open + 1 >= close)
    {
        output[open + close] = '(';
        toHop(n, open + 1, close);
    }
    if (close < n && open >= close)
    {
        output[open + close] = ')';
        toHop(n, open, close + 1);
    }
}
#include <fstream>

void readWriteFile()
{
    //	freopen("input.txt","r",stdin);
    //	freopen("output.txt","w",stdout);
    // ----------------------C ++ --------------
    //    string s;
    //    //read
    //    ifstream infile;
    //    infile.open("hoclaptrinh.dat");
    //    while (!infile.eof()) {
    //        getline(infile, s);
    //        cout << s << " \n";
    //    }
    //    infile.close();
    //
    //    //write
    //    ofstream osfile;
    //    osfile.open("hoclaptrinh.dat", ios::app); // ( app - ghi them vao file)
    //    cin >> s;
    //    osfile << s;
    //    osfile.close();

    //--------------------------- C ----------------
    //read
    //    char name[30];
    //    FILE *fi = fopen("hoclaptrinh.dat", "r");     // mo file de doc
    //    while(!feof(fi)){
    //      	fgets(name,255,fi);
    //   		puts(name);
    //	}
    //    fclose(fi);
    //
    //    //write
    //    FILE *fo = fopen("hoclaptrinh.dat", "a");    // mo file de ghi (r - read , w- write, a - add)
    //    gets(name);
    //   	fputs(name,fo);
    //    fclose(fo);
}

void readWriteFileBinary()
{
    //------------- C ------------------
    //read
    int n;
    //	FILE *fi = fopen("hoclaptrinh.dat", "r");
    //	while(fread(&n,sizeof(int),1,fi)){
    //		printf("%d\n",n);
    //	}
    //	fclose(fi);
    //
    //	//write
    //	scanf("%d",&n);
    //	FILE *fo = fopen("hoclaptrinh.dat", "a");
    //	fwrite(&n,sizeof(int),1,fo);
    //	fclose(fo);

    //------------- C++ ----------------------
    //read
    ifstream in;
    in.open("hoclaptrinh.dat");
    while (in.read(reinterpret_cast<char *>(&n), sizeof(int)))
    {
        cout << n << "\n";
    }
    in.close();
    //write
    ofstream out;
    out.open("hoclaptrinh.dat", ios::app);
    cin >> n;
    out.write(reinterpret_cast<char *>(&n), sizeof(int));
    out.close();
}

float arr[] = {3, 5, 6, 10, 20};
//float arr[]={1,2,3,5,9,15};
void myMerge(char nameFile[10], int n)
{
    fstream in;
    in.open(nameFile);

    float x = 0;
    in.read(reinterpret_cast<char *>(&x), sizeof(float));
    int i = 0;
    while (i < n)
    {
        if (arr[i] < x)
        {
            printf("%.2f ", arr[i++]);
        }
        else
        {
            printf("%.2f ", x);
            if (!in.read(reinterpret_cast<char *>(&x), sizeof(float)))
            {
                break;
            }
        }
    }

    if (i < n)
    {
        while (i < n)
        {
            printf("%.2f ", arr[i++]);
        }
    }
    else
    {
        do
        {
            printf("%.2f ", x);
        } while (in.read(reinterpret_cast<char *>(&x), sizeof(float)));
    }

    in.close();
}

void writeArray(char nameFile[])
{
    fstream out;
    out.open(nameFile);
    out.write(reinterpret_cast<char *>(&arr), sizeof(arr));
    out.close();
}

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct point
{
    double x, y;
};

bool cmp_x(const point &a, const point &b)
{
    return a.x < b.x;
}

bool cmp_y(const point &a, const point &b)
{
    return a.y < b.y;
}

#define MAXN 100000
point a[MAXN];
double mindist; // bi?n luu k?t qu? b�i to�n

// t�nh kho?ng c�ch gi?a a v� b r?i update k?t qu?
void upd_ans(const point &a, const point &b)
{
    double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    if (dist < mindist)
        mindist = dist;
}

void find(int l, int r)
{
    if (r <= l)
        return;
    // do?n [l,r] c� 2 ph?n t?
    if (r == l + 1)
    {
        upd_ans(a[l], a[r]);
        // s?p c�c ph?n t? l?i theo y
        if (!cmp_y(a[l], a[r]))
            swap(a[l], a[r]);
        return;
    }

    int m = (l + r) / 2;
    int midx = a[m].x;
    find(l, m);
    find(m + 1, r);

    static point t[MAXN];
    // tr?n a[l,m] v� a[m+1,r] l?i, luu v�o m?ng t?m t
    merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, cmp_y);
    // copy t? t v? l?i a
    copy(t, t + r - l + 1, a + l);

    // m?ng t ? d�y luu c�c ph?n t? th?a |x_i - midx| < mindist,
    // v?i s? lu?ng ph?n t? l� tm
    // do d� sort n�n c�c ph?n t? s? c� y tang d?n
    int tm = 0;
    for (int i = l; i <= r; i++)
        if (abs(a[i].x - midx) < mindist)
        {
            for (int j = tm - 1; j >= 0 && t[j].y > a[i].y - mindist; j--)
                upd_ans(a[i], t[j]);
            t[tm++] = a[i];
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    mindist = 1E20;
    sort(a, a + n, cmp_x);
    find(0, n - 1);

    printf("%.3lf", mindist);
    return 0;
}
