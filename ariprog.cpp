/*
ID: gateaux1
PROG: ariprog
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int a[2*250*250+1]={0};

int check(int start,int diff,int N){if(a[start]){
                                            for(int i=start+diff;i<=start+(N-1)*diff;i+=diff){
                                                                                                if(a[i]==0)return false;
                                                                                             }
                                             return true;
                                            }
                                    else{ return false;}
                                    }
int main(){

ifstream fin ("ariprog.in");
ofstream fout ("ariprog.out");
int N,M;
int flag =0;

fin >> N >> M;
for(int i=0;i<=M;i++){
                     for(int j=0;j<=i;j++){ a[i*i+j*j] = 1;
                                          }
                     }
for(int diff=1;diff<=2*M*M/(N-1);diff++){
                                     for(int i=0;i<=2*M*M-diff*(N-1);i++){
                                                if(check(i,diff,N)){ flag = 1;
                                                        fout << i << " " << diff << endl;}
                                                }
}
if(!flag)fout << "NONE" << endl;
return 0;
}
