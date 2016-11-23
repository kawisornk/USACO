/*
 ID: gateaux1
 PROG: combo
 LANG: C++
 */
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int distance(int a,int b,int N){ int x = int(abs(b-a));
                                 int y = N - x;
    return (x<y)?x:y;
                               }
int main(){ ofstream fout ("combo.out");
            ifstream fin ("combo.in");
            int N;
            fin >> N;
    int j[3],m[3];
    fin >> j[0] >> j[1] >> j[2] >> m[0] >> m[1] >> m[2];
    int a=0,b=0,c=0;
    a = distance(j[0],m[0],N);
    b = distance(j[1],m[1],N);
    c = distance(j[2],m[2],N);
    if(N>=5){
    a = (a>4)?0:5-a;
    b = (b>4)?0:5-b;
    c = (c>4)?0:5-c;
    fout << 250-a*b*c<< endl;}
    else fout << N*N*N << endl;
    return 0;
}
