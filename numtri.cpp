/*
ID: gateaux1
PROG: numtri
LANG: C++
*/

#include<iostream>
#include<fstream>
using namespace std;

int max(int a,int b){   return (a>b)?a:b;
                    }

int main(){
ifstream fin ("numtri.in");
ofstream fout ("numtri.out");
int R;
fin >> R;
int a[R+1][R+2];
int b[R+1][R+2];
b[R-1][R]=0;
b[0][0]=0;
for(int i=1;i<=R;i++){ b[i][0]=0;
                       b[0][i]=0;

                       for(int j=1;j<=i;j++){ fin >> a[i][j];}
                       for(int j=i+1;j<=i+1;j++){ b[i][j]=0;}
                    }
for(int i=1;i<=R;i++){
                    for(int j=1;j<=i;j++){ b[i][j] = a[i][j] + max(b[i-1][j-1],b[i-1][j]);
                                         }
}
int m=0;
for(int i=1;i<=R;i++){ m = (m>b[R][i])?m:b[R][i];
                     }
fout << m << endl;
return 0;
}
