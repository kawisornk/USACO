/*
ID: gateaux1
PROG: sort3
LANG: C++
*/
#include<iostream>
#include<fstream>
int s;
int func(int a[],int N,int inv){ int flag=0;
            for(int i=0;i<N-1;i++){
                for(int j=i+1;j<N;j++){
                                        if(a[i]>a[j]){ int k;
                                                       k=a[i];
                                                       a[i]=a[j];
                                                       a[j]=k;
                                                       func(a,N,inv+1);
                                                       a[j]=a[i];
                                                       a[i]=k;
                                                       flag=1;
                                                     }
                                        }

            }
        if(flag==0)s=(s<inv)?s:inv;
}
using namespace std;

int main(){
ifstream fin ("sort3.in");
ofstream fout ("sort3.out");
int N;
fin >> N;
s = N;
int a[N];
for(int i=0;i<N;i++){   fin >> a[i];
                    }
func(a,N,0);
fout << s <<endl;
return 0;
}
