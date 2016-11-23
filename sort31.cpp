/*
ID: gateaux1
PROG: sort3
LANG: C++
*/
#include<iostream>
#include<fstream>

using namespace std;

int main(){
ifstream fin ("sort3.in");
ofstream fout ("sort3.out");
int N;
fin >> N;
int s12=0,s13=0,s21=0,s23=0,s31=0,s32=0;
int s=0;
int a[N],b[4]={0};
for(int i=0;i<N;i++){   int k;
                        fin >> k;
                        a[i]=k;
                        b[k]++;
                    }
for(int i=0;i<b[1];i++){
    if(a[i]==2){ s12++;}
    else if(a[i]==3){ s13++;}
}
for(int i=b[1];i<b[2]+b[1];i++){
    if(a[i]==1){ s21++;}
    else if(a[i]==3){ s23++;}
}
for(int i=b[2]+b[1];i<N;i++){
    if(a[i]==1){ s31++;}
    else if(a[i]==2){ s32++;}
}
//exchange (i,j)
int m=min(s12,s21);
s+=m;
s12-=m;
s21-=m;
//cout << s << endl;
m=min(s13,s31);
s+=m;
s13-=m;
s31-=m;
//cout << s << endl;
//exchange (i,j,k)
m=s21;
s += 2*m;
s32-=m;
m=s31;
s += 2*m;
s23 -=m;
s+= s23;

fout << s <<endl;
return 0;
}
