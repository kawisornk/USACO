/*
ID: gateaux1
PROG: hamming
LANG: C++
*/

#include<iostream>
#include<fstream>
using namespace std;
int table[256][256];
int a[65];
//2^b
int exp(int b){ if(b==0)return 1;
                else{ return 2*exp(b-1); }
              }
//hamming distance
int hd(int a,int b){  unsigned int z;
                      z=a^b;
                      int d=0;
                     while(z){ d++;
                                z&= z-1;
                            }
                    return d;
                         }
//find if there is an answer,starting with i;
int answer(int n,int i,int d){ a[0]=i;
                        int c=1; //c = length of current sequence
                      for(c=1;c<=n;c++){ if(c==n)return true;
                                         else { int j;
                                                for(j=a[c-1]+1;j<=256;j++){ if(j==256)return false;
                                                                                else {int k=0;
                                                                                      for(k=0;k<c;k++){ if(table[j][a[k]]<d)break;
                                                                                                      }
                                                                                        if(k==c)break; // integer j can be used
                                                                                     }
                                                                              }
                                                 a[c] = j;
                                                }
                                        }

}
int main(){
ifstream fin ("hamming.in");
ofstream fout ("hamming.out");
int n,b,d;
fin >> n >> b >> d;
b=exp(b);
for(int i=0;i<=b;i++){
                    for(int j=0;j<=i;j++){
                                        table[i][j] = hd(i,j);
                                        }
                    }
for(int j=0;j<256;j++){
                        if(answer(n,j,d))break;
}
for(int j=0;j<n;j++){
                        if(j==n-1)fout << a[j] << endl;
                        else if(j%10==9)fout << a[j] << endl;
                        else fout << a[j] << " ";
                    }
return 0;
}

