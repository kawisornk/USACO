/*
ID: gateaux1
PROG: castle
LANG: C++
*/

#include<iostream>
#include<fstream>
int a[52][52][4]; // 0 = W, 1 = N,2 = E, 3 = S
int component[52][52];
int s[2500]={0}; //size of each component;
using namespace std;

void func(int row,int column,int k){
unsigned int z = 1;
for(int i=0;i<4;i++){
    if(z&k){a[row][column][i]=1;
           z*=2;
         }
    else { a[row][column][i]=0;
           z*=2;
         }
}
}

void floodfill(int comp,int row,int column){ int num_visited;
do{ num_visited = 0;
    for(int i=1;i<=row;i++){
                            for(int j=1;j<=column;j++){
                                                        if(component[i][j]==-2){ num_visited++;
                                                                                if(a[i][j][0]==0&&component[i][j-1]==-1){component[i][j-1]=-2;
                                                                                              }

                                                                                if(a[i][j][1]==0&&component[i-1][j]==-1){component[i-1][j]=-2;
                                                                                              }

                                                                                if(a[i][j][2]==0&&component[i][j+1]==-1){component[i][j+1]=-2;
                                                                                              }

                                                                                if(a[i][j][3]==0&&component[i+1][j]==-1){component[i+1][j]=-2;
                                                                                              }
                                                                                component[i][j]=comp;
                                                                                s[comp]++;
                                                                                }
                                                        }
                            }
}while(num_visited>0);
}


int main(){
int M,N; // M column, N row
ifstream fin ("castle.in");
ofstream fout ("castle.out");
fin >> M >> N;
for(int i=1;i<=N;i++){ component[i][M+1]=0;
                      for(int j=1;j<=M;j++){ component[N+1][j]=0;
                                            int k;
                                            fin >> k;
                                            func(i,j,k);
                                            component[i][j]=-1;
                                            }
                     }
int comp=0;
for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
                            if(component[i][j]==-1){    comp++;
                                                        component[i][j]=-2;
                                                        floodfill(comp,N,M);
                                                    }
                         }
                     }
fout << comp << endl;
int maxsize=0;
for(int i=1;i<=comp;i++){
    maxsize = (maxsize>s[i])?maxsize:s[i];
}
fout << maxsize << endl;
maxsize =0;
char c;
int i1,i2;
for(int j=M;j>=1;j--){
        for(int i=1;i<=N;i++){  if(component[i][j]!=component[i][j+1]){int x = s[component[i][j]] + s[component[i][j+1]];
                                                                        if(x>=maxsize){ maxsize = x;
                                                                                       c = 'E';
                                                                                       i1=i;
                                                                                       i2=j;
                                                                                     }
                                                                        }
                                if(component[i][j]!=component[i-1][j]){int x = s[component[i][j]] + s[component[i-1][j]];
                                                                        if(x>=maxsize){ maxsize = x;
                                                                                        c = 'N';
                                                                                        i1=i;
                                                                                        i2=j;
                                                                                     }
                                                                        }
                                }
                    }
fout << maxsize << endl;
fout << i1 << " " << i2 << " " << c << endl;
}
