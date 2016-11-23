/*
ID: gateaux1
PROG: nocows
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

long long answer[200][100] = {0};
int main(){
ifstream fin ("nocows.in");
ofstream fout ("nocows.out");
int N,K;
fin >> N >> K;
if(N%2==0 || N>=pow(2,K)){ fout << 0 << endl;
                            return 0;
                            }
for(int i=1;i<=N;i+=2){
                        for(int j=1;j<=K;j++){
                                            if(i>=pow(2,j)){ answer[i][j]=0;} //not possible
                                            else if(i==pow(2,j)-1){ answer[i][j]=1;} //complete binary tree
                                            else{
                                                  for(int k=1;k<(i-1)/2;k+=2){
                                                                        for(int l=1;l<j-1;l++){
                                                                                              answer[i][j] += (answer[k][j-1]*answer[i-k-1][l])%9901; //left child has k nodes
                                                                                              answer[i][j] += (answer[k][l]*answer[i-k-1][j-1])%9901;
                                                                                              }
                                                                            answer[i][j]+= answer[k][j-1]*answer[i-k-1][j-1];
                                                                            answer[i][j]%=9901;
                                                                       }
                                                            answer[i][j]*=2;
                                                            int z=(i-1)/2;
                                                            if(z%2 == 1){
                                                                                for(int l=1;l<j-1;l++){
                                                                                              answer[i][j] += (answer[z][j-1]*answer[z][l])%9901; //left child has k nodes
                                                                                              answer[i][j] += (answer[z][l]*answer[z][j-1])%9901;
                                                                                              }
                                                                                answer[i][j]+=answer[z][j-1]*answer[z][j-1];
                                                                                }
                                                            answer[i][j]%=9901;
                                                }
                                            }
                     }
fout << answer[N][K] << endl;
return 0;
}

