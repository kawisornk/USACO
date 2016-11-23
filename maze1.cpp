/*
ID: gateaux1
PROG: maze1
LANG: C++
*/

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cstdio>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;
ifstream fin("maze1.in");
ofstream fout("maze1.out");

int m=0,W,H;
int a[3800][3800];
char s[210][100];
int d[3801];

void dijit(int k){
int next=k,current=W*H+1;
int c=W*H;
int visit[W*H];

for(int i=0;i<W*H;i++){ visit[i]=0;
                        d[i]=W*H+1;
                        }
d[k]=0;
while(c>0){ visit[next]=1;
            for(int i=0;i<W*H;i++){ if(a[i][next]==1){ d[i]=(d[i]<d[next]+1)?d[i]:d[next]+1;}

            }
            current = W*H+1;
            for(int i=0;i<W*H;i++){ if((visit[i]==0) && d[i]<=current){
                                                                        next =i;
                                                                        current = d[i];
                                                                        }

                                    }
            c--;
          }
for(int i=0;i<W*H;i++){ m =(m>=d[i])?m:d[i];
                      }
}

int main(){

vector<int> exit;
fin>>W>>H;

	for(int i=0;i<2*H+1;i++)
	{
	    fin.get();
		for(int j=0;j<2*W+1;j++)
		{
			s[i][j]=fin.get();
		}
	}
for(int i=0;i<W*H;i++){
    for(int j=0;i<W*H;j++){
            a[i][j]=0;
}
}

for(int i=0;i<2*H+1;i++){

    if(i==0){ for(int j=1;j<2*W+1;j+=2){ if(s[0][j]!='-'){  exit.push_back((j-1)/2);}

                                        }

            }
    else if(i==2*H){ for(int j=1;j<2*W+1;j+=2){ if(s[2*H][j]!='-'){ exit.push_back(W*(H-1)+(j-1)/2);}

                                              }

                   }
    // vertical walls
    else if(i%2==1){ if(s[i][0]!='|'){ exit.push_back((i-1)*W/2);} //the first column is W*i
                     if(s[i][2*W]!='|'){ exit.push_back((i+1)*W/2-1);}
                     for(int j=2;j<2*W;j+=2){
                                                if(s[i][j]!='|'){ int k=(i-1)*W/2+j/2;
                                                                a[k][k-1] =1;a[k-1][k] = 1;
                                                             }
                                             }

                    }
        //horizontal walls
     else if(i%2==0){
                     for(int j=1;j<2*W;j+=2){
                                                if(s[i][j]!='-'){ int k=i*W/2+(j-1)/2;
                                                                a[k][k-W] =1;a[k-W][k] = 1;
                                                             }
                                             }

                    }
}


dijit(exit[0]);
dijit(exit[1]);
fout << m << endl;
return 0;
}
